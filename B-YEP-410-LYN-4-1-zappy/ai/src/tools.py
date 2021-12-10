class TOOLS:
    def array_cleanner(self, array):
        return list(map(lambda x: x.strip().split(), array[1:-1].split(',')))

    def receive_message(self, socket):
        message = ""
        while True:
            try: character = socket.recv(1).decode()
            except Exception: break
            if (character == "\n"): break
            else: message += character
        return message

    def inventory_cleanner(self, array):
        return [item for sublist in map(lambda x: x.strip().split(), array[1:-1].split(',')) for item in sublist]

    def get_inventory(self, data, value):
        for element in data:
            if (element["name"] == value):
                return (element["quantity"])
        return (0)

    def get_players(self, data):
        return data.count("player")
