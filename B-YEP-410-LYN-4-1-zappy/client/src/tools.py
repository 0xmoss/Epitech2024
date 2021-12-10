class TOOLS:
    @staticmethod
    def receive_message(socket):
        message = ""
        while True:
            try:
                character = socket.recv(1).decode()
            except:
                return None
            if (character == "\n"):
                break
            else:
                message += character
        return message
