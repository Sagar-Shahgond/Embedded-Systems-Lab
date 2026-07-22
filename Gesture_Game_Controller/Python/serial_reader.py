import serial
from config import COM_PORT, BAUD_RATE

ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)

def read_packet():
    try:
        line = ser.readline().decode().strip()

        if not line:
            return None

        parts = line.split(",")

        if len(parts) != 3:
            return None

        throttle = int(parts[0])
        brake = int(parts[1])
        direction = int(parts[2])

        return throttle, brake, direction

    except Exception:
        return None