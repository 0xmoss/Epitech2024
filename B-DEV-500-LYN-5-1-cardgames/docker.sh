#!/usr/bin/env bash

function start()
{
    printf "Starting docker\n"
    sudo systemctl start docker.service
    sudo systemctl enable docker.service
    sudo docker info
    printf "Docker started\n"

    printf "Starting mongodb\n"
    sudo systemctl enable --now mongodb
    sudo systemctl start --now mongodb
    printf "Mongodb started\n"
}

function stop()
{
    printf "Stopping docker\n"
    sudo systemctl stop docker.service
    sudo systemctl disable docker.service
    sudo docker info
    python3 Dashboard/scripts/gdc.py revert
    printf "Docker stopped\n"

    printf "Stopping mongodb\n"
    sudo systemctl disable --now mongodb
    sudo systemctl stop --now mongodb
    printf "Mongodb stopped\n"
}

function run()
{
    printf "Running Dashboard\n"
    python3 Dashboard/scripts/gdc.py dump
    sudo docker-compose build && sudo docker-compose up
    python3 Dashboard/scripts/gdc.py revert
    printf "Dashboard ran\n"
}

function main()
{
    command="start / stop / run"
    found="false"

    if [[ $1 == "start" ]]; then
        found="true"
        start
    fi    
    if [[ $1 == "stop" ]]; then
        found="true"
        stop
    fi
    if [[ $1 == "run" ]]; then
        found="true"
        run
    fi

    if [[ $found == "false" ]]; then
        printf "usage: $command\n"
    fi
}

main $1
