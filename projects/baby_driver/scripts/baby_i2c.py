'''Baby Driver's I2C Control Script'''


def i2c_write(port, address, tx_bytes, reg=None):
    '''
    Writes over I2C to the given port/address
    Args:
        port: port of the I2C to write to (1 or 2)
        address: I2C address to write to (0-255)
        tx_bytes: list of bytes to write over I2C (a list of ints 0-255)
        reg: the register to write to, or None if no register is required
    Raises:
        Exception: if a non-zero status code was received
    '''
    if port not in (1, 2):
        raise ValueError("ERROR: Expected port of 1 (I2C_PORT_1) or 2 (I2C_PORT_2)")

    if address < 0 or address >= 255:
        raise ValueError("ERROR: Expected address between 0 and 255")

    if not all(0 <= byte < 256 for byte in tx_bytes):
        raise ValueError("Expected list of bytes between 0 and 255")

    is_reg = 0
    if reg is None:
        reg = 0
    else:
        is_reg = 1
    if reg < 0 or reg > 255:
        raise ValueError("Expected register to write to between 0 and 255")

  # MESSAGE HANDLING UART? HOPEFULLY
