'''Baby Driver's Interrupt Control Script'''
from variables import GpioPort, NUM_PINS_PER_PORT

class InterruptEdge:
    # pylint: disable=too-few-public-methods
    '''Stores interrupt edge values'''
    RISING = 0
    FALLING = 1
    RISING_AND_FALLING = 2
    NUM_INTERRUPT_EDGES = 3

def register_gpio_interrupt(port, pin, edge=InterruptEdge.RISING_AND_FALLING, callback=None):
    '''
    Registers a gpio interrupt on a pin

    Args:
        port: port of the GPIO pin to register an interrupt in
        pin: pin number of the GPIO pin to register an interrupt in
        edge: callback function is called when this interrupt edge occurs. Can be entered as a
              string or a number (RISING (0), FALLING (1) or RISING_AND_FALLING (2))
        callback: if callback is None, a default callback function will be called
                  that prints "Interrupt on P<port><pin>: <edge>" in this format.
                  The user-defined callback function should follow this format:
                  function_name(info) where the only parameter is info,
                  a named tuple which holds the port (info.port),pin (info.pin) and
                  edge (info.edge) of the GPIO interrupt that occured.

    Raises:
        Value error: if the parameters passed into register_gpio_interrupt are incorrect
        Attribute error: if the port parameter or interrupt edge is invalid (refer gpio_port.py
                         for acceptable port parameters and InterruptEdge for appropriate edge
                         parameters)
        Exception: if a non-zero status code is received when attempting to register an interrupt
        Type error: if the callback function (called when interrupt occurs) is of incorrect format

    Note: There is a hard STM32 limit that only one GPIO interrupt can be registered at a time
    per pin number. For example, PA2 and PB2 would share the same GPIO pin.
    '''
    if isinstance(port, str):
        port = getattr(GpioPort, port.capitalize())

    if port < 0 or port >= GpioPort.NUM_GPIO_PORTS:
        raise ValueError("ERROR: Expected port between A and {}".format(
            chr(GpioPort.NUM_GPIO_PORTS + ord('A') - 1)
        ))

    if pin < 0 or pin >= NUM_PINS_PER_PORT:
        raise ValueError("ERROR: Expected pin between 0 and {}".format(NUM_PINS_PER_PORT - 1))

    if isinstance(edge, str):
        if edge.upper() not in InterruptEdge.__members__:
            raise AttributeError("ERROR: 'RISING', 'FALLING', 'RISING_AND_FALLING' for edge")
        edge = InterruptEdge[edge.upper()]

    if edge < 0 or edge >= InterruptEdge.NUM_INTERRUPT_EDGES:
        raise ValueError("ERROR: Invalid edge, 0 (Rising), 1 (Falling), 2 (Rising_and_falling)")

    if callback is not None and not callable(callback):
        raise ValueError("invalid callback function")

    # MESSAGE HANDLING UART? HOPEFULLY
