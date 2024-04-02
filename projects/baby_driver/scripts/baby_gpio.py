'''Baby Driver's Gpio Control Script'''
from variables import GpioPort, NUM_PINS_PER_PORT


def gpio_set(port, pin, state):
    '''
    Sets a GPIO pin
    Args:
        port: port of the GPIO pin to set (can be entered as either a string or integer)
        pin: pin number of the GPIO pin to set
        state: 0 if setting low, 1 if setting high
    Raises:
        AttributeError: if port parameter is entered as a string and is invalid
        ValueError: if parameters passed into gpio_set are invalid
        Exception: if a non-zero status code was received
    '''

    # If given port as a string, it is converted to a string
    if isinstance(port, str):
        port = getattr(GpioPort, port.capitalize())

    if port < 0 or port >= GpioPort.NUM_GPIO_PORTS:
        raise ValueError("ERROR: Expected port between A and {}".format(
            chr(GpioPort.NUM_GPIO_PORTS + ord('A') - 1)
        ))

    if pin < 0 or pin >= NUM_PINS_PER_PORT:
        raise ValueError("ERROR: Expected pin between 0 and {}".format(NUM_PINS_PER_PORT - 1))

    if state not in (0, 1):
        raise ValueError("ERROR: Expected state of 0 (low) or 1 (high)")

    # MESSAGE HANDLING UART? HOPEFULLY


def gpio_get(port, pin):
    '''
    Gets a GPIO pin state
    Args:
        port: port of the GPIO pin to get (can be entered as either a string or integer)
        pin: pin number of the GPIO pin to get
    Raises:
        AttributeError: if port parameter is entered as a string and is invalid
        ValueError: if parameters passed into gpio_get are invalid
        Exception: if a non-zero status code was received
    '''

    # If given port as a string, it is converted to a string
    if isinstance(port, str):
        port = getattr(GpioPort, port.capitalize())

    if port < 0 or port >= GpioPort.NUM_GPIO_PORTS:
        raise ValueError("Expected port between A and {}".format(
            chr(GpioPort.NUM_GPIO_PORTS + ord('A') - 1)
        ))

    if pin < 0 or pin >= NUM_PINS_PER_PORT:
        raise ValueError("Expected pin between 0 and {}".format(NUM_PINS_PER_PORT - 1))

    # MESSAGE HANDLING UART? HOPEFULLY
