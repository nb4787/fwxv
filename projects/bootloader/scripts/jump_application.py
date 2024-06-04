from can_datagram import Datagram, DatagramSender
from validation import Validation

CAN_ARBITRATION_JUMP_ID = 0b00000000010

class Jump_Application:
    def __init__(self, sender=None) -> None:
        if sender:
            self._sender = sender
        else:
            self._sender = DatagramSender()

    def start_jump_process(self, board_nums: int, jump_app_id: int) -> None:
        if not Validation.validate_board_id(board_nums) and not Validation.validate_jump_size(jump_app_id):
            print(f'Error starting jump application, boards {board_nums} or app id {jump_app_id} is not valid')
            return

        print(f"Starting jump process for boards {board_nums}...")

        board_id = list(range(board_nums + 1))

        datagram_id = CAN_ARBITRATION_JUMP_ID | (board_nums << 5)

        # Create a datagram with the jump message
        #Send an int to jump to that file (max 2^16-1 possible applications)
        jump_datagram = Datagram(
            datagram_type_id=datagram_id,
            node_ids=board_id,
            data=bytearray(jump_app_id)
        )

        self._sender.send(jump_datagram)
        
        print(f"Jump process initiated for board {board_id}...")
