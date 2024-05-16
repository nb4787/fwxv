from can_datagram import Datagram, DatagramSender, DatagramListener

class Flash_Application():
    def __init__(self, listener: DatagramListener, sender: DatagramSender) -> None:
        self.listener = listener
        self.sender = sender
    
    
    def handle_sending(self, datagram: Datagram, board_id: int):
        pass

    def flash_application_process(self, datagram: Datagram, board_id: int):
        print(f"Starting flash application process for board {board_id}...")
        
        #TODO Perform actual flash application logic here

        print(f"Flash application completed for board {board_id}")


    def start_flash_process(self):
        pass


if __name__ == "__main__":
    sender = DatagramSender()

    listener = DatagramListener(callback=False) #TODO all real flash callback

    flash_app = Flash_Application(listener, sender)

    
