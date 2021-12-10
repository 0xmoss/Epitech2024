#!/usr/bin/env bash

function stop()
{
    printf "[.] stopping previous mongodb services\n"
    sudo systemctl stop mongodb
    printf "[-] stopping previous mongodb services\n"
}

function run()
{
    mongod --dbpath ./DashboardDB
}

run
