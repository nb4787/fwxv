'''Baby Driver's ADC Control Script'''
from variables import GpioPort

ADC_PINS = [
    {"port": GpioPort.A, "pin": 0},
    {"port": GpioPort.A, "pin": 1},
    {"port": GpioPort.A, "pin": 2},
    {"port": GpioPort.A, "pin": 3},
    {"port": GpioPort.A, "pin": 4},
    {"port": GpioPort.A, "pin": 5},
    {"port": GpioPort.A, "pin": 6},
    {"port": GpioPort.A, "pin": 7},
    {"port": GpioPort.B, "pin": 0},
    {"port": GpioPort.B, "pin": 1}
]


def adc_read(port, pin, raw=False):
    '''
    Reads a raw or converted ADC value.

    Args:
        port: The port of the GPIO pin to read from.
        pin: The pin number of the GPIO pin to read from.
        raw: If raw is True, a raw read should be performed; otherwise a converted read.
            Defaults to converted.

    Returns:
        The ADC reading as a 16-bit integer.

    Raises:
        ValueError: if the range of the input args is invalid.
        Exception: if we receive a nonzero status code.
    '''

    # If port is entered as a str, convert to int
    if isinstance(port, str):
        port = getattr(GpioPort, port.capitalize())

    if {"port": port, "pin": pin} not in ADC_PINS:
        raise ValueError("ERROR: Expected valid ADC port")

    if raw not in (True, False):
        raise ValueError("ERROR: Expected raw to be a bool value")

    # MESSAGE HANDLING UART? HOPEFULLY
