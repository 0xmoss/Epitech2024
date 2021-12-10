#!/usr/bin/env python3

def build(name):
    f = open("src/signals/{}.c".format(name.lower()), 'w+')
    f.write("/*\n");
    f.write("** EPITECH PROJECT, 2020\n");
    f.write("** B-PSU-402-LYN-4-1-strace-\n");
    f.write("** File description:\n");
    f.write("** {}.c\n".format(name));
    f.write("*/\n\n");

    f.write("#include \"handler.h\"\n\n");
    f.write("#include \"PHASEOUT.h\"\n\n");
    f.write("#include \"strace.h\"\n\n");

    f.write("size_t {}(int *signal, size_t display)\n".format(name.lower()));
    f.write("{\n");
    f.write(f"    if (WSTOPSIG(*signal) == {name.upper()}) {'{'}\n");
    f.write("        if (display == True)\n");
    f.write(f"            printf(\"{name.upper()}\\n\");\n");
    f.write("        return (True);\n");
    f.write("    }\n");
    f.write("    return (False);\n");
    f.write("}\n");

    f.close()

def main():
    data = None

    while (data != "EXIT"):
        data = input("SIGNAL: ")
        build(data)

if (__name__ == "__main__"):
    main()