#!/usr/bin/env bash

function stop()
{
    printf "[.] stopping previous mongodb services\n"
    sudo systemctl stop mongodb
    printf "[+] previous mongodb services stopped\n"
}

function run()
{
    printf "[.] running mongodb services\n"
    mongod --dbpath ./DashboardDB
    printf "[+] mongodb services running\n"
}

function main()
{
    if [[ $1 == "run" ]]; then
        run
    else
        stop
    fi
}

main $1
