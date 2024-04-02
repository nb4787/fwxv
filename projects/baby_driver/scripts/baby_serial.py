'''Baby Driver's Main Setup Script'''
import subprocess
import serial

OUTPUT = subprocess.check_output(["ls", "/dev/serial/by-id/"])
DEVICE_PATH = f"/dev/serial/by-id/{str(output, 'ASCII').strip()}"

serialDevice = serial.Serial(device_path, 115200)