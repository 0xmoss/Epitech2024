import re
import os
import sys

from src.errors import ERRORS

class TOOLS:
    def __init__(self, settings):
        self.errors = ERRORS()
        self.path = None
        self.data = None
        self.elements = ["city", "number", "street_type", "street_name"]
        self.settings = settings
        self.status = self.arguments()
        self.weight = {}
        self.run = 0
        self.truncs = ["city", "street_name"]
        self.input = ""
        self.validation = {
            "city" : False,
            "name" : False,
            "address" : False
        }

    def arguments(self):
        try:
            if (len(sys.argv) != 2):
                self.errors.invalid_argument()
            if (sys.argv[1] == "-h"):
                self.help()
                return (-1)
            if (os.path.isfile(sys.argv[1]) == True):
                self.path = sys.argv[1]
                return (0)
            self.errors.invalid_argument()
        except Exception as e:
            print(e)
            exit(84)

    def help(self):
        content = self.settings.settings["help"]

        for line in content:
            print(line)

    def get_status(self):
        return (self.status)

    def get_path(self):
        return (self.path)

    def get_content(self):
        content = []
        line = "_EMPTY_"

        if (os.stat(self.path).st_size > 0):
            with open(self.path, 'r') as f:
                while (line):
                    line = f.readline()
                    if (line):
                        content.append(self.remove_line(line))
            f.close()
            self.settings.settings["address"]["choices"] = content
            return (content)
        else:
            exit(84)

    def debug(self, element):
        if (self.settings.settings["debug"] == True):
            print(element)

    @classmethod
    def remove_line(self, element):
        if ('\n' in element):
            element = element.replace('\n', '')
        return (element)

    @classmethod
    def remove_coma(self, element):
        if (',' in element):
            element = element.replace(',', '')
        return (element)

    def clean(self, element):
        element = self.remove_line(element)
        element = self.remove_coma(element)
        return (element)

    def extractor(self, line):
        splitted = line.split(' ')
        score = 0
        self.data = {
            "city" : self.get_city(splitted),
            "number" : self.get_number(splitted),
            "street_type" : self.get_street_type(splitted),
            "street_name" : self.get_street_name(splitted)
        }

        for element in self.elements:
            if (self.data[element] != None):
                score += 1
        if (score == 0):
            return (None)
        if (score == 4):
            if (self.data not in self.settings.settings["address"]["address"]):
                self.settings.settings["address"]["address"].append(self.data)
        return (self.data)

    def has_coma(self, line):
        for element in line:
            if (',' in element):
                return (True)
        return (False)

    def get_city(self, data):
        city = ""
        space = ''
        street = False

        if (self.has_coma(data) == True):
            for i, element in enumerate(data):
                if (element not in self.settings.settings["address"]["street_type"]["types"] and
                    element.isnumeric() == False and
                    element != '\n'):
                    if (i > 1):
                        if (data[i - 1] in self.settings.settings["address"]["street_type"]["types"]):
                            street = True
                    if (street == False):
                        if (len(city) > 0):
                            space = ' '
                        if (',' in element):
                            element = self.clean(element)
                            city += "{}{}".format(space, element)
                            return (city)
                        element = self.clean(element)
                        city += "{}{}".format(space, element)
                    elif (',' in element):
                        street = False
                elif (len(city) > 0):
                    return (city)
            if (len(city) == 0):
                city = None
            return (city)
        else:
            return (None)


    def get_number(self, data):
        for element in data:
            element = self.clean(element)
            if (element.isnumeric() == True):
                return (element)
        return (None)

    def get_street_type(self, data):
        for element in data:
            element = self.clean(element)
            for type in self.settings.settings["address"]["street_type"]["types"]:
                if (element == type):
                    return (element)
        return (None)

    def get_street_name(self, data):
        name = ""
        space = ''
        city = self.get_city(data)

        for element in data:
            element = self.remove_line(element)
            if (element != city and element not in self.settings.settings["address"]["street_type"]["types"] and ',' not in element and
                element.isnumeric() == False and
                element not in self.settings.settings["address"]["street_type"]["types"]):
                if (len(name) > 0):
                    space = ' '
                name += "{}{}".format(space, element)
            elif (len(name) > 0):
                return (name)
        if  (name == ""):
            name = None
        return (name)

    def parser(self, data):
        result = None
        problems = []
        problem = False

        for content in data:
            if (len(self.remove_line(content)) > 0):
                result = self.extractor(content)
                for element in self.elements:
                    if (len(element) > 0):
                        if (result[element] == None and problem == False):
                            problem = True
                if (problem == True):
                    problems.append(self.remove_line(content))
                    problem = False
        if (len(problems) > 0):
            self.errors.display_errors(problems)

    def dump_sort(self, data_type, display_mod = False):
        space = ''
        result = []
        same = []
        display = []
        weight = sorted(self.weight.values())[::-1]

        self.debug("self.weight at launch: {}".format(self.weight))
        for value in weight:
            for element in self.weight.keys():
                if (element not in result and self.weight[element] == value):
                    same.append(element.lower())
            same.sort()
            if (same not in result):
                result.append(same.copy())
            same.clear()

        self.debug("Sorted: {}".format(result))
        for array in result:
            for element in array:
                if (element not in display):
                    display.append(element)
        if (display_mod == True):
            self.dump_display(display)
        else:
            self.settings.settings["prediction"]["sort"] = display.copy()

    def dump_display(self, result):
        space = ''
        letters = []

        self.debug(result)
        for data in result:
            if (data not in letters):
                letters.append(data)

        if (len(letters) > 1):
            for i, city in enumerate(letters):
                if (i < 5):
                    if (i > 0):
                        space = ' '
                    print("{}{}{}{}".format(space, '{', city, '}'), end = '')
            print()

    def dump_display_partial(self, city, result):
        space = ''
        letters = []

        self.debug("Partial display: {}".format(result))
        for data in result:
            if (data not in letters):
                letters.append(data)

        for i, d in enumerate(letters):
            if (i < 5):
                if (i > 0):
                    space = ' '
                print("{}{}{}, {}{}{}".format(space, '{', city, self.input.upper(), result, '}'), end = '')
        print()

    def dump(self, data_type, display):
        unlocked = []
        same = True

        self.debug("Dumping address: {}".format(self.settings.settings["address"]["address"]))
        for element in self.truncs:
            if (len(self.settings.settings["prediction"][element]) == 1):
                unlocked.append(element)

        self.debug("====> Unlocked: {}".format(unlocked))
        self.debug("State: {}".format(self.weight))

        for i, address in enumerate(self.settings.settings["address"]["address"]):
            self.debug("Checking: {}".format(address[data_type]))
            if (' ' in address[data_type]):
                splitted = address[data_type].split(' ')
                for content in splitted:
                    if (len(unlocked) > 0):
                        for unlock in unlocked:
                            self.debug("---> Address: {} Unlock: {}".format(address[unlock].upper(), self.settings.settings["prediction"][unlock]))
                            if (address[unlock].upper() in self.settings.settings["prediction"][unlock]):
                                if (content[0] not in self.weight):
                                    self.weight[content[0]] = 1
                                    self.debug("-> Added: {}".format(content))
                                    if (address[data_type] not in self.settings.settings["address"][data_type]["choices"]):
                                        self.settings.settings["address"][data_type]["choices"].append(address[data_type])
                                else:
                                    self.weight[content[0]] += 1
                                    self.debug("-> Updated: {}".format(content))
                    else:
                        if (content[0] not in self.weight):
                            self.weight[content[0]] = 1
                            self.debug("-> Added: {}".format(content))
                            if (address[data_type] not in self.settings.settings["address"][data_type]["choices"]):
                                self.settings.settings["address"][data_type]["choices"].append(address[data_type])
                        else:
                            self.weight[content[0]] += 1
                            self.debug("-> Updated: {}".format(content))
            else:
                if (len(unlocked) > 0):
                    for unlock in unlocked:
                        if (address[unlock].upper() in self.settings.settings["prediction"][unlock]):
                            if (address[data_type][0] not in self.weight):
                                self.weight[address[data_type][0]] = 1
                                self.debug("-> Added: {}".format(address[data_type]))
                                if (address[data_type] not in self.settings.settings["address"][data_type]["choices"]):
                                    self.settings.settings["address"][data_type]["choices"].append(address[data_type])
                            else:
                                self.weight[address[data_type][0]] += 1
                                self.debug("-> Updated: {}".format(address[data_type]))
                else:
                    if (address[data_type][0] not in self.weight):
                        self.weight[address[data_type][0]] = 1
                        if (address[data_type] not in self.settings.settings["address"][data_type]["choices"]):
                            self.settings.settings["address"][data_type]["choices"].append(address[data_type])
                    else:
                        self.weight[address[data_type][0]] += 1
            for element in self.elements:
                self.settings.settings["address"][element]["choices"].append(address[element])
        self.debug(self.settings.settings["address"])
        self.debug("weight: {}".format(self.weight))
        for i in range(0, len(self.settings.settings["address"]["city"]["choices"])):
            if (i > 0):
                if (self.settings.settings["address"]["city"]["choices"][i] != self.settings.settings["address"]["city"]["choices"][i - 1]):
                    same = False

        if (same == False):
            self.dump_sort(data_type, display)
        else:
            if (len(self.settings.settings["address"]["city"]["choices"]) > 0):
                if (len(self.settings.settings["address"]["city"]["choices"][0]) > 0):
                    self.prediction(self.settings.settings["address"]["city"]["choices"][0][0])

    def prediction(self, input_data) -> False:
        purge = False
        self.input = ""

        for character in input_data:
            self.input += character.lower()
            self.debug("self.input: {}".format(self.input))
            if (self.validation["city"] == False):
                if (purge == True):
                    self.weight = {}
                    purge = False
                if (len(self.settings.settings["prediction"]["city"]) > 1 or
                    (self.run <= 0 and len(self.settings.settings["prediction"]["city"]) == 0)):
                    self.prediction_city()
                    self.validation["city"] = self.truncate(self.settings.settings["prediction"]["city"], "city")
                    if (self.validation["city"] == True):
                        purge = True
                elif (self.run > 0 and len(self.settings.settings["prediction"]["city"]) == 0):
                    self.errors.unknown_address()
            if (self.validation["city"] == True):
                if (self.validation["name"] == False):
                    if (purge == True):
                        self.weight = {}
                        purge = False
                    if (len(self.settings.settings["prediction"]["street_name"]) > 1 or
                        (self.run < 0 and len(self.settings.settings["prediction"]["street_name"]) == 0)):
                        self.prediction_name()
                        self.validation["name"] = self.truncate(self.settings.settings["prediction"]["street_name"], "street_name")
                        if (self.validation["name"] == True):
                            purge = True
                    elif (self.run > 0 and len(self.settings.settings["prediction"]["street_name"]) == 0):
                        self.errors.unknown_address()
                if (self.validation["name"] == True):
                    if (self.validation["address"] == False):
                        if (purge == True):
                            self.weigh = {}
                            purge = False
                        if (len(self.settings.settings["prediction"]["address"]) > 1 or
                            (self.run <= 0 and len(self.settings.settings["prediction"]["address"]) == 0)):
                            self.prediction_address()
                            self.validation["address"] = self.truncate(self.settings.settings["prediction"]["address"], "address")
                        elif (self.run <= 0 and len(self.settings.settings["prediction"]["address"]) == 0):
                            self.errors.unknown_address()
            self.run += 1
            self.prediction_display_found()
        if (self.validation["city"] == False):
            self.prediction_display_city()
        elif (self.validation["name"] == False):
            self.prediction_display_name()
        elif (self.validation["address"] == False or self.validation["address"] == True):
            self.prediction_display_address()
        if (self.input.isnumeric() == True):
            self.prediction_display_found()

    def prediction_city(self):
        self.debug("predicting city...")
        self.weight.clear()
        for address in self.settings.settings["address"]["address"]:
            address = address["city"].lower()
            if (' ' in address):
                address = address.split(' ')
                for word in address:
                    if (word.startswith(self.input) == True):
                        if (word not in self.low_array(self.settings.settings["prediction"]["city"])):
                            self.settings.settings["prediction"]["city"].append(word)
                    else:
                        if (word in self.low_array(self.settings.settings["prediction"]["city"])):
                            self.settings.settings["prediction"]["city"].remove(word)
            else:
                if (address.startswith(self.input) == True):
                    if (address not in self.low_array(self.settings.settings["prediction"]["city"])):
                        self.settings.settings["prediction"]["city"].append(address)
                else:
                    if (address in self.low_array(self.settings.settings["prediction"]["city"])):
                        self.settings.settings["prediction"]["city"].remove(address)
        self.debug("City prediction: {}".format(self.settings.settings["prediction"]["city"]))

    def name_cleanner(self, name, address_city, fixed_address):
        if (name.startswith(self.input) == True and address_city == fixed_address):
            if (name[0] not in self.weight):
                self.weight[name[0]] = 1
            else:
                self.weight[name[0]] += 1
            if (name not in self.low_array(self.settings.settings["prediction"]["street_name"])):
                self.settings.settings["prediction"]["street_name"].append(name)
        else:
            if (name[0] in self.weight.keys()):
                if (self.weight[name[0]] <= 1):
                    del self.weight[name[0]]
                else:
                    self.weight[name[0]] -= 1
            if (name in self.settings.settings["prediction"]["street_name"]):
                self.settings.settings["prediction"]["street_name"].remove(name)

    def prediction_name(self):
        fixed_address = self.settings.settings["prediction"]["city"][0].lower()

        self.debug("predicting name...")
        self.weight.clear()
        for address in self.settings.settings["address"]["address"]:
            address_city = address["city"].lower()
            address_name = address["street_name"].lower()
            if (' ' in address_name):
                address_name = address_name.split(' ')
                for word in address_name:
                    self.name_cleanner(word, address_city, fixed_address)
            else:
                self.debug("-> self.weight: {} address[0]: {}".format(self.weight, address_name[0]))
                self.debug("checking name: {}\nwith:\n\t- self.input: {}\n\t- fixed_address: {}\n\t- address_city: {}".format(
                    address_name,
                    self.input,
                    fixed_address,
                    address_city
                ))
                self.debug("address_name[0]: {}\nkeys: {}\n".format(address_name[0], list(self.weight.keys())))
                self.debug("address: {} starts with: {} : {}".format(address_name, self.input, address_name.startswith(self.input)))
                self.name_cleanner(address_name, address_city, fixed_address)
        self.dump_sort("street_name", False)
        self.debug("Name prediction: {}".format(self.settings.settings["prediction"]["street_name"]))

    def prediction_address(self):
        fixed_city = self.settings.settings["prediction"]["city"][0].lower()
        fixed_name = self.settings.settings["prediction"]["street_name"][0].lower()
        full_address = None

        self.debug("predicting address...")
        self.weight.clear()
        for address in self.settings.settings["address"]["address"]:
            self.debug("Checking address: {}".format(address))
            address_city = address["city"].lower()
            address_name = address["street_name"].lower()
            address_type = address["street_type"].lower()
            full_address = "{}, {} {} {}".format(
                address["city"].upper(),
                address["number"],
                address["street_type"],
                address["street_name"].upper()
            )
            self.debug("City result: {} : {}".format(address_city, fixed_city))
            self.debug("Name result: {} : {}".format(address_name, fixed_name))
            self.debug("Full address: {}".format(full_address))
            if (address_city == fixed_city and
                fixed_name in address_name):
                if (address not in self.low_array(self.settings.settings["prediction"]["address"])):
                    self.settings.settings["prediction"]["address"].append(full_address)
            else:
                if (address in self.low_array(self.settings.settings["prediction"]["address"])):
                    self.settings.settings["prediction"]["address"].remove(full_address)
        self.debug("Address prediction: {}".format(self.settings.settings["prediction"]["address"]))

    def truncate(self, array, types):
        result = None
        valid = 0
        score = 0

        if (len(array) > 0):
            self.debug("Array: {}".format(array))
            self.settings.settings["prediction"]["truncated"].clear()
            if (len(array) != 1):
                for element in array:
                    result = element[len(self.input):]
                    for i in range(0, len(result)):
                        for data in self.settings.settings["prediction"]["truncated"]:
                            if (result[:i + 1].startswith(data) == False):
                                score += 1
                        if (score == len(self.settings.settings["prediction"]["truncated"])):
                            self.settings.settings["prediction"]["truncated"].append(result[:i + 1])
                        score = 0
            else:
                self.debug("Type: {} is done".format(types))
                self.settings.settings["prediction"][types] = []
                self.settings.settings["prediction"][types].append(array[0].upper())
                self.run = -1
                self.input = ""
                return (True)
        return (False)

    def prediction_display_city(self):
        space = ''
        data = self.settings.settings["prediction"]["truncated"]

        if (len(data) > 0):
            for i, element in enumerate(data):
                if (i < 5):
                    if (i > 0):
                        space = ' '
                    print("{}{}{}{}{}".format(
                        space,
                        '{',
                        self.input.upper(),
                        element,
                        '}'
                    ), end = '')
            print()
        else:
            self.errors.unknown_address()

    def prediction_display_name(self):
        space = ''
        data = self.settings.settings["prediction"]["truncated"]
        sort = self.settings.settings["prediction"]["sort"]
        name = self.settings.settings["prediction"]["street_name"]

        self.debug("data: {}\nsort: {}\nname: {}".format(data, sort, name))

        if (len(sort) > 1):
            for i, element in enumerate(sort):
                if (i < 5):
                    if (i > 0):
                        space = ' '
                    print("{}{}{}, {}{}{}".format(
                        space,
                        '{',
                        self.settings.settings["prediction"]["city"][0],
                        self.input.upper(),
                        element,
                        '}'
                    ), end = '')
            print()
        elif (len(data) >= 1):
            for i, element in enumerate(data):
                if (i < 5):
                    if (i > 0):
                        space = ' '
                    else:
                        space = ''
                    print("{}{}{}, {}{}{}".format(
                        space,
                        '{',
                        self.settings.settings["prediction"]["city"][0],
                        self.input.upper(),
                        element,
                        '}'
                    ), end = '')
            print()
        else:
            self.errors.unknown_address()

    def prediction_display_address(self):
        space = ''
        data = self.settings.settings["prediction"]["address"]

        self.debug("Displaying: {}".format(data))
        if (len(data) > 1):
            for i, element in enumerate(data):
                if (i < 5):
                    if (i > 0):
                        space = ' '
                    print("{}{}{} : {}{}".format(
                        space,
                        '{',
                        i + 1,
                        element,
                        '}'
                    ), end = '')
            print()
        elif (len(data) <= 1):
            self.prediction_display_found()
        else:
            self.errors.unknown_address()

    def prediction_display_found(self):
        data = self.settings.settings["address"]["address"]
        result = []

        if (len(self.settings.settings["prediction"]["city"]) == 1 and
            len(self.settings.settings["prediction"]["street_name"]) == 1):
            for address in data:
                self.debug("address[city].lower(): {}\nprediction: {}".format(address["city"].lower(), self.settings.settings["prediction"]["city"][0].lower()))
                self.debug("address[street_name].lower(): {}\nprediction: {}".format(
                    address["street_name"].lower(),
                    self.settings.settings["prediction"]["street_name"][0].lower()))
                if (address["city"].lower() == self.settings.settings["prediction"]["city"][0].lower() and
                    self.settings.settings["prediction"]["street_name"][0].lower() in address["street_name"].lower()):
                    result.append(address)

        self.debug("Data: {}\nResut: {}\n".format(data, result))
        self.debug(self.input)
        if (len(data) == 1):
            self.debug("display 1")
            print("=> {}, {} {} {}".format(
                data[0]["city"],
                data[0]["number"],
                data[0]["street_type"],
                data[0]["street_name"]
            ))
            exit(0)
        elif (len(result) == 1):
            self.debug("display 2")
            print("=> {}, {} {} {}".format(
                result[0]["city"],
                result[0]["number"],
                result[0]["street_type"],
                result[0]["street_name"]
            ))
            exit(0)
        elif (len(result) > 1 and len(self.input) > 0):
            self.debug("display 3")
            if (self.input.isnumeric() == True):
                self.input = int(self.input) - 1
                if (self.input < len(result)):
                    print("=> {}, {} {} {}".format(
                        result[self.input]["city"],
                        result[self.input]["number"],
                        result[self.input]["street_type"],
                        result[self.input]["street_name"]
                    ))
                    exit(0)
                else:
                    self.errors.unknown_address()

    def low_array(self, array):
        cpy = array.copy()

        if (len(cpy) > 0):
            for i, element in enumerate(cpy):
                cpy[i] = element.lower()

        self.debug("\t-> Lowed: {}".format(cpy))
        return (cpy)

