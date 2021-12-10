class LOGS:
    data = {
        "reset" : "0",
        "red" : "31",
        "green" : "32",
        "yellow" : "33",
        "blue" : "34",
        "purple" : "35",
        "cyan" : "36",
        "white" : "37"
    }

    @classmethod
    def colors(cls, color, font):
        if (cls.data.get(color) != None and (font >= 0 and font <= 5)):
            return ("\033[{};{}m".format(font, cls.data.get(color)))
        return (None)

    @classmethod
    def status(cls, data, status, color, font, mod):
        if (mod == 0):
            print("{}{}{}{}".format(
                cls.colors(color, font),
                status,
                data,
                cls.colors("reset", 0)
            ))
        if (mod == 1):
            print("{}[ {} ]{} {}".format(
                cls.colors(color, font),
                status,
                cls.colors("reset", 0),
                data
            ))
        if (mod == 2):
            print("{}{}{} {}".format(
                cls.colors(color, font),
                status,
                cls.colors("reset", 0),
                data
            ))


    @classmethod
    def ok(cls, data):
        cls.status(data, "  OK  ", "green", 0, 1)

    @classmethod
    def ko(cls, data):
        cls.status(data, "  KO  ", "red", 0, 1)

    @classmethod
    def done(cls, data):
        cls.status(data, " DONE ", "green", 0, 1)

    @classmethod
    def fail(cls, data):
        cls.status(data, " FAIL ", "red", 0, 1)

    @classmethod
    def warning(cls, data):
        cls.status(data, " !!!! ", "purple", 0, 1)

    @classmethod
    def missing(cls, data):
        cls.status(data, "CONFIG", "purple", 0, 1)

    @classmethod
    def load(cls, data):
        cls.status(data, " ---- ", "yellow", 0, 1)

    @classmethod
    def display(cls, data):
        cls.status(data, "=====>", "green", 0, 1)

    @classmethod
    def signal(cls, data):
        print("{}[ SIGNAL ]{} {}".format(
            cls.colors("yellow", 0),
            cls.colors("reset", 0),
            data
        ), end = '\r')

    @classmethod
    def recv(cls, data):
        cls.status(data, " RECV ", "blue", 0, 1)

    @classmethod
    def send(cls, data):
        cls.status(data, " SEND ", "cyan", 0, 1)

    @classmethod
    def item(cls, data):
        cls.status("   --> {}".format(data), " ---> ", "yellow", 0, 1)

