import serial
import serial.tools.list_ports
import time
from config import BAUD_RATE, COM_PORT

class SerialReader:

    def __init__(self):

        if COM_PORT is None:
            self.port = self.find_arduino()
        else:
            self.port = COM_PORT

        if self.port is None:
            raise Exception("Arduino not found!")

        print(f"Connecting to {self.port}")

        self.ser = serial.Serial(
            self.port,
            BAUD_RATE,
            timeout=1
        )

        time.sleep(2)

    def find_arduino(self):

        ports = serial.tools.list_ports.comports()

        for port in ports:

            print(f"Found: {port.device} -> {port.description}")

            if (
                "Arduino" in port.description or
                "USB Serial" in port.description or
                "Nano" in port.description
            ):
                return port.device

        return None

    def read(self):

        try:

            line = self.ser.readline().decode().strip()

            if line == "":
                return None

            data = line.split(",")

            if len(data) != 3:
                return None

            throttle = int(data[0])
            brake = bool(int(data[1]))
            direction = int(data[2])

            return throttle, brake, direction

        except:
            return None