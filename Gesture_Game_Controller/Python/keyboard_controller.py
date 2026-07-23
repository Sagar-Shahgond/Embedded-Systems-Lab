import pydirectinput
import time
from config import *

class GameController:

    def __init__(self):

        self.right_pressed = False
        self.left_pressed = False

    def press_right(self):

        if not self.right_pressed:
            pydirectinput.keyDown("right")
            self.right_pressed = True

    def release_right(self):

        if self.right_pressed:
            pydirectinput.keyUp("right")
            self.right_pressed = False

    def press_left(self):

        if not self.left_pressed:
            pydirectinput.keyDown("left")
            self.left_pressed = True

    def release_left(self):

        if self.left_pressed:
            pydirectinput.keyUp("left")
            self.left_pressed = False

    def update(self, throttle, brake, direction):

        # Highest Priority
        if brake:

            self.release_right()
            self.press_left()
            return

        self.release_left()

        if throttle > THROTTLE_THRESHOLD:
            self.press_right()
        else:
            self.release_right()

        # Balance correction
        # Balance correction disabled for testing
        pass
        '''if direction == LEFT_DIRECTION:

            self.release_right()

            pydirectinput.press("left")

            time.sleep(BALANCE_TAP_TIME)

            if throttle > THROTTLE_THRESHOLD:
                self.press_right()'''