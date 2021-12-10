import sys

class ERRORS:
    @classmethod
    def invalid_argument(cls):
        raise Exception("Invalid argument")

    @classmethod
    def display_errors(cls, element):
        for address in element:
            print(address, file = sys.stderr)

    @classmethod
    def unknown_address(cls):
        raise Exception("Unknown address")

