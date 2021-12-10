# MyTeams

## How to send request to the server

### First step

First of all we are going to describe how to send request to the server.
To do so you have to define which command and arguments you are sending to the server in a structure.

This structure is defined in `src/include/global_struct.h` as `struct request_data`
You first need to fill the info field which represents which arguments you are sending to the server.

There is a list of all possible arguments in file `src/include/global_enum.h` defined as the enum request_info.

This enum act as a bitmask so to combine multiple arguments you just have to do it like that `(UUID0 | NAME)`

Then you have to fill the command field which represent the command you are using (without the slash and it's mandatory)

After that you need to fill each one of the arguments you are using and sending to the server.

### Second step

Second step is to send everything to the server.

You have to send the info field as a byte first then you have to send each field individually in the order of how the structure is defined from top to bottom and sending exactly a specific amount of bytes for each which are defined in `src/include/global_define.h` in the form of `MAX_*_LENGTH` (you have to replace the star with which the argument name you are sending).

For example if you have to send one uuid and a name, you should in order send it like that:

* info field as one byte
* command field as `MAX_COMMAND_LENGTH` bytes
* uuid0 field as `MAX_UUID_LENGTH` bytes
* name field as `MAX_NAME_LENGTH` bytes

### Final step

After sending your request you will receive a response.

This response which have a 15 bytes header representing in the first 5 bytes the response code which can be converted as a number and cast to a enum response_code defined in `src/include/global_enum.h` and in the 10 following bytes the response message's size in byte.

Everything following this header will be the response's message send by the server. This overall can be converted to a struct response_data defined in `src/include/global_struct.h`.

## Response's message format

First of all I'm precising the response code as a string that correspond to enum response_code defined in `src/include/global_enum.h`

Second of all you need to understand that each data field are described as `FIELD_NAME(FIELD_DATA)` and everytime I fill `FIELD_DATA` it's only for example purpose.

### /create

#### /use (create a team)

OK - `New team created with UUID(2b26c813-adbc-44eb-a273-84066b7cff0e) NAME(test) DESCRIPTION(test description)`

#### /use team_uuid (create a channel)

OK - `New channel created with UUID(2b26c813-adbc-44eb-a273-84066b7cff0e) NAME(test) DESCRIPTION(test description)`

#### /use team_uuid channel_uuid (create a thread)

OK - `New thread created with UUID(2b26c813-adbc-44eb-a273-84066b7cff0e) USER_UUID(2a87ba93-b22e-4385-829b-653c333e47c0) TIME(1622943820) NAME(test) BODY(test message)`

#### /use team_uuid channel_uuid thread_uuid (create a reply)

OK - `New reply created with TEAM_UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) THREAD_UUID(2b26c813-adbc-44eb-a273-84066b7cff0e) USER_UUID(2a87ba93-b22e-4385-829b-653c333e47c0) TIME(1622943820) BODY(test reply message)`

### /help

The response message is a formatted string representing info about all existing commands. You just have to display it.

### /info

#### /use (info about your user)

OK - `Your info are UUID(2a87ba93-b22e-4385-829b-653c333e47c0) NAME(test) CONNECTED(1)`

#### /use team_uuid (info about a team)

OK - `Selected team info are UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) DESCRIPTION(test description)`

#### /use team_uuid channel_uuid (info about a channel)

OK - `Selected channel info are UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) DESCRIPTION(test description)`

#### /use team_uuid channel_uuid thread_uuid (info about a thread)

OK - `Selected team info are UUID(ea5bd9e-adea-4672-905a-5a624d45cd99 AUTHOR_UUID(2a87ba93-b22e-4385-829b-653c333e47c0) TIME(1622943820) NAME(test) BODY(test message)`

### /list

The response message is describe as list of message splitted by newline character.

#### /use (list of all teams)

OK - `UUID(2a87ba93-b22e-4385-829b-653c333e47c0) NAME(test) DESCRIPTION(text description)`

#### /use team_uuid (list of all channels)

OK - `UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) DESCRIPTION(test description)`

#### /use team_uuid channel_uuid (list of all teams)

OK - `UUID(ea5bd9e-adea-4672-905a-5a624d45cd99 AUTHOR_UUID(2a87ba93-b22e-4385-829b-653c333e47c0) TIME(1622943820) NAME(test) BODY(test message)`

#### /use team_uuid channel_uuid thread_uuid (list of all teams)

OK - `UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) AUTHOR_UUID(2a87ba93-b22e-4385-829b-653c333e47c0) TIME(1622943820) BODY(test message)`

### /login user_name

OK - `You are now authenticated as NAME(test) UUID(2a87ba93-b22e-4385-829b-653c333e47c0).`

KO - `Someone is already authenticated as NAME(test).`

### /logout

OK - `You are now disconnected.`

### /messages user_uuid

OK - `TIME(1622943820) NAME(test) BODY(test message)` (as a list separated by newline character)

OK - `You have no active conversation with this user.`

KO - `This user does not exist.`

### /send user_uuid message_body

OK - `The message has been send.`

OK - `This user is not connected.`

KO - `This user does not exist.`

### /subscribe team_uuid

OK - `You are now subscribed to this team.`

KO - `Team with UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) does not exist.`

### /subscribed

#### /subscribed (no arguments)

OK - `You are currently subscribed in:` + `UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) DESCRIPTION(test description)` (as a list separated by newline character)

#### /subcribed team_uuid

OK - `The users subscribed to this team are:` + `UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) CONNECTED(0)` (as a list separated by newline character)

KO - `This team doesn't exist.`

### /unsubscribe team_uuid

OK - `You were unsubscribed from this team.`

OK - `You weren't subscribed from this team.`

KO - `This team doesn't exist.`

### /use

#### /use (no arguments)

OK - `No context provided.`

#### /use team_uuid

OK - `Context changed successfully.`

KO - `Team with UUID(2a87ba93-b22e-4385-829b-653c333e47c0) doesn't exist.`

#### /use team_uuid channel_uuid

OK - `Context changed successfully.`

KO - `Channel with UUID(2a87ba93-b22e-4385-829b-653c333e47c0) doesn't exist.`

#### /use team_uuid channel_uuid thread_uuid

OK - `Context changed successfully.`

KO - `Thread with UUID(2a87ba93-b22e-4385-829b-653c333e47c0) doesn't exist.`

### /user user_uuid

OK - `This user is UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) CONNECTED(0)`

KO - `This user does not exist.`

### /users

OK - `UUID(ea5bd9e-adea-4672-905a-5a624d45cd99) NAME(test) CONNECTED(0)` (as a list separated by newline character)
