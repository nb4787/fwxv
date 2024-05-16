import unittest

from jump_application import Jump_Application
from can_datagram import Datagram, DatagramListener, DatagramSender

TEST_CHANNEL = 'vcan0'

class TestJumpApplication(unittest.TestCase):

    def test_handle_datagram(self):
        self._callback_triggered = False

        listener = DatagramListener(self._callback_triggered)
        sender = DatagramSender(bustype="virtual", channel=TEST_CHANNEL, receive_own_messages=True)
        jump_app = Jump_Application(listener, sender)

        
        