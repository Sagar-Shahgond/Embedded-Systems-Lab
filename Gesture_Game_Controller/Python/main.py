from serial_reader import SerialReader
from keyboard_controller import GameController
from utils import print_packet

print("----------------------------------------")
print("Gesture Gaming Controller")
print("----------------------------------------")

reader = SerialReader()
controller = GameController()

while True:

    packet = reader.read()

    if packet is None:
        continue

    throttle, brake, direction = packet

    '''print_packet(
        throttle,
        brake,
        direction
    )'''

    controller.update(
        throttle,
        brake,
        direction
    )