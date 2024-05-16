from can_datagram import Datagram, DatagramSender, DatagramListener

class Jump_Application:
    def __init__(self, listener: DatagramListener, sender: DatagramSender) -> None:
        self.sender = sender
        self.listener = listener

    def handle_datagram(self, datagram: Datagram, board_id: int):
        pass

    def jump_application_process(self, datagram: Datagram, board_id: int):
        print(f"Starting jump application process for board {board_id}...")
        
        #TODO Perform actual jump application logic here

        print(f"Jump application completed for board {board_id}")

    def start_jump_process(self):
        pass


if __name__ == "__main__":
    sender = DatagramSender()
    listener = DatagramListener(callback=False)

    jump_app = Jump_Application(listener, sender)