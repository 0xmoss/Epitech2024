# AbstractVM

## Goal: A simple Virtual Machine for a Simple Assembler

### Commands available

##### push
```
Stack the v value at the top. The v value will naturally take one of the following forms: int8(n), int16(n),
int32(n), float(z), double(z) or bigdecimal(z).
(For example : int16(n) - create an signed 16-bit integer with the value n)
```
##### pop
```
Unstacks the value at the top of the stack. If the stack is empty the program’s execution must stop
error.
```
##### dump
```
Display each value on the stack from the newest to the oldest, WITHOUT MODIFYING the stack.
Each value is separated from the next with a line break
```
##### clear
```
Clears the stack. Rendering it empty.
```
##### dup
```
Duplicates the value on the top of the stack, and stacks the copy of the value
```
##### swap
```
Reverses the order of (swaps) the top two values on the stack.
```
##### assert
```
erify that the value at the top of the stack is equal to the one passed as parameter in this instruction.
If it’s not the case, the program execution must stop error. The v value, of course, has the same form
as those passed as parameter during the push instruction.
```
##### add
```
Unstack the first two values in the stack, add them, and then stack the result. If the number of values
in the stack is strictly less than 2, the program execution must stop error
```
##### sub
```
Unstack the first two values in the stack, substract them, and then stack the result. If the number of
values in the stack is strictly less than 2, the program execution must stop error.
```
##### mul
```
Unstack the first two values in the stack, multiply them, and then stack the result. If the number of
the values in the stack is strictly less than 2, the program execution must stop error.
```
##### div
```
Unstack the first two values in the stack, divide them, and then stack the result. If the number of the
values in the stack is strictly less than 2, the program execution must stop error. Also, if the divisor is
equal to 0, the program execution must also stop error.
```
##### mod
```
Unstack the first two values in the stack, calculate their modulo, and then stack the result. If the num-
ber of the values in the stack is strictly less than 2, the program execution must stop error. Also, if the
divisor is equal to 0, the program execution must also stop error.
```
##### load
```
Copy the value from the register v and stack it at the top. if the register v does not contain a value,
the program execution must stop error.
```
##### store
```
Unstack the first value and store it to the register v.
```
##### print
```
Make sure that the value at the top of the stack is an 8-bit integer (if this is not the case, see the
assert instruction), then interpret it like an ASCII value and display the corresponding character on
the standard output.
```
##### exit
```
Quit the program execution that is underway. If this instruction does not appear, despite the fact that
all of the instructions have been executed, the execution must stop error.
```

### Types availables

- [X] int8
- [X] int16
- [X] int32
- [X] float
- [X] double
- [X] bigdecimal

### Error management

```
FILE_NOT_FOUND "file not found: "
OVERFLOW "overflow on a value: "
UNDERFLOW "underflow on a value: "
SHORT_STACK "the stack must have two value at least: "
EMPTY_STACK "pop instruction on an empty stack: "
EMPTY_REGISTER "load instruction on an empty register: "
SYNTACTICAL "the assembler program has one, or several, syntactical errors: "
DIVISION_ZERO "division by zero: "
EXIT "the program does not have an exit instruction: "
ASSERT "an assert instruction is not verified: "
ARITHMETICAL "the stack strictly has less than two values during the execution of an arithmetical instruction: "
LEXICAL "the assembler program has one, or several, lexical errors: "
COMMAND_NOT_FOUND "invalid command: "
TYPE_NOT_FOUND "type not found: "
PARENTHESE_MISSING "missing parenthesis: "
COMMAND_TYPE_INVALID "command type invalid: "
COMMAND_TYPE_IS_REQUIRED "a command type is required: "
COMMAND_TYPE_IS_NOT_REQUIRED "no command type is required: "
INVALID_TYPE_VALUE "the value entered is not the good type: "
BAD_FORMAT_TYPE_VALUE "bad format for type value: "
WRONG_TYPE_VALUE "wrong type value: "
MODULO_ZERO "modulo error: modulo by zero: "
MODULO_FLOAT "modulo error: modulo by floating: "
```

### Tests

#### How to do a test file
- Create a file with the extension '.avm'
- Store it in the resources/ folder
- Edit the content for your test
- Run 'launch' from the root of the project

#### Launch
```
make
chmod +x test/launch
./test/launch
```

#### Result
```
[  ....  ] Launching 'resources/bad_format_type_value.avm'
bad format for type value: 33.3..3

[  ....  ] Launching 'resources/div_by_0.avm'
division by zero: 0

[  ....  ] Launching 'resources/double_no_decimal.avm'
1793

[  ....  ] Launching 'resources/example_0.avm'
42
42.42
3341.25

[  ....  ] Launching 'resources/example.avm'
42
42.42
3341.25

[  ....  ] Launching 'resources/invalid_command.avm'
invalid command: issou

[  ....  ] Launching 'resources/invalid_type_value.avm'
the value entered is not the good type:

[  ....  ] Launching 'resources/no_exit.avm'
the program does not have an exit instruction: 'exit'

[  ....  ] Launching 'resources/not_required.avm'
no command type is required: add

[  ....  ] Launching 'resources/print_test.avm'
8
the value entered is not the good type: 56

[  ....  ] Launching 'resources/push_bigdecimal.avm'
wrong type value: 42

[  ....  ] Launching 'resources/push_double.avm'

[  ....  ] Launching 'resources/push_float.avm'

[  ....  ] Launching 'resources/push_int16.avm'
wrong type value: 42.42

[  ....  ] Launching 'resources/push_int32.avm'
wrong type value: 42.42

[  ....  ] Launching 'resources/push_int8.avm'
wrong type value: 42.42

[  ....  ] Launching 'resources/required.avm'
a command type is required: push

[  ....  ] Launching 'resources/unknown_command.avm'
invalid command: pull

[  ....  ] Launching 'resources/unknown_type.avm'
type not found: UNKNOWN

[  ....  ] Launching 'resources/wrong_type_value.avm'
wrong type value: 33.1
```
