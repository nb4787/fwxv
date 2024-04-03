'''Baby Driver's SPI Control Script'''


def spi_exchange(tx_bytes, rx_len, spi_port=1, spi_mode=0, baudrate=6000000):
    '''
    Sends data through SPI
        The tx_bytes is an int array
        The rx_len is a non-negative int.
        The spi_port is a non-negative int.
        The spi_mode is a non-negative int.
        The baudrate is a non-negative int.
        The CS pin, if not None, is a tuple (port, pin), where pin is an
            int in [0, NUM_PINS_PER_PORT) and port is either an int in [0, NUM_GPIO_PORTS),
            or a string 'a' through 'f', case insensitive
    Args:
        tx_bytes: The bytes to TX.
        rx_len: Number of bytes to RX
        spi_port: port of the pin to perform SPI exchange on (1 or 2)
        spi_mode: SPI mode to use (0, 1, 2 or 3)
        baudrate: baudrate to use (defaults to 6000000)
        cs: chip select port and pin to use (defaults to (1, 1))
    Raises:
        AttributeError: if cs_port parameter is entered as a string and is invalid
        ValueError: if spi_port, spi_mode, rx_len, cs_port, cs_pin don't meet their requirements
        Exception: if a non-zero status code was received.
    '''
    if spi_port not in (1, 2):
        raise ValueError("ERROR: Expected port of 1 (SPI_PORT_1) or 2 (SPI_PORT_2)")

    if spi_mode not in (0, 1, 2, 3):
        raise ValueError("ERROR: Expected mode between 0 and 3")

    if not 0 <= len(tx_bytes) <= 255:
        raise ValueError("ERROR: numbers of tx_bytes must be between 0 and 255")

    if not all(0 <= byte < 256 for byte in tx_bytes):
        raise ValueError("Expected list of bytes between 0 and 255")

    if baudrate < 0:
        raise ValueError("ERROR: baudrate must be a non-negative integer")

    # MESSAGE HANDLING UART? HOPEFULLY
