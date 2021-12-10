#!/bin/bash

port_1=5000
port_2=5001
image_1=poll
image_2=redis
image_3=result
image_4=worker

init_docker()
{
    printf "Creating Dockerfiles...\n"

    echo "FROM python:3.7-alpine as $image_1
WORKDIR /app
ENV FLASK_APP app.py
ENV FLASK_RUN_HOST 0.0.0.0
COPY . /app
RUN apk add --no-cache gcc musl-dev linux-headers
RUN pip install -r requirements.txt
EXPOSE 80
CMD [\"flask\", \"run\", \"--host=0.0.0.0\", \"--port=80\"]" > poll/Dockerfile


    echo "FROM node:12-alpine as $image_2
WORKDIR /app
COPY . /app
RUN npm install
EXPOSE 80
ENV PORT 80
CMD [\"node\", \"server.js\"]" > result/Dockerfile

    echo "FROM openjdk:3.5-jdk-8-alpine as $image_3
WORKDIR /app
COPY . /app
RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:8-jre-alpine
EXPOSE 80
COPY --from=$image_3 /app/target/worker-jar-with-dependencies.jar .
CMD [\"java\", \"-jar\", \"worker-jar-with-dependencies.jar\""> worker/Dockerfile

    echo "version: \"3\"
services:

  $image_1:
    build: ./$image_1
    restart: always
    links:
      - $image_2
      - db
    depends_on:
      - $image_2
    ports:
      - \"5000:80\"
    networks:
      - $image_1-tier
    environment:
      - 0.0.0.0

  $image_2:
    image: $image_2:buster
    restart: always
    expose:
      - 6379
    ports:
      - \"6379:6379\"
    networks:
      - $image_1-tier
      - back-tier

  $image_3:
    build: ./$image_3
    restart: always
    networks:
      - back-tier
    environment:
      - 0.0.0.0

  db:
    image: postgres:13.0
    restart: always
    networks:
      - $image_4-tier
      - back-tier
    volumes:
      - db-data:/var/lib/postgresql/data
      - \"./schema.sql:/docker-entrypoint-initdb.d/init.sql\"
    environment:
      - \"POSTGRES_USER=postgres\"
      - \"POSTGRES_PASSWORD=password\"

  $image_4:
    build: ./$image_4
    restart: always
    ports:
      - \"5001:80\"
    networks:
      - $image_4-tier
    environment:
      - 0.0.0.0

networks:
  $image_1-tier:
  $image_4-tier:
  back-tier:

volumes:
  db-data:" > docker-compose.yml

    printf "Dockerfiles created\n"
}

init_configuration()
{
    printf "Creating configuration...\n"

    echo "[uwsgi]
module = main
callable = app
master = true
    " > poll/uwsgi.ini

    printf "Configuration created\n"
}

init_launcher()
{
    printf "Creating builder...\n"

    echo "#!/bin/bash

printf \"\e[1;31m Weclome into popeye by Neo\e[0;0m\n\n\"

app_1=\"$image_1\"
app_2=\"$image_2\"
app_3=\"$image_3\"

build_image_1()
{
    printf \"\e[1;33m BUILDING | : \"$image_1\"\e[0;0m\n\"
    sudo docker build poll
    printf \"\e[1;32m DONE     | : \"$image_1\"\e[0;0m\n\"
}

build_image_2()
{
    printf \"\e[1;33m BUILDING | : \"$image_2\"\e[0;0m\n\"
    sudo docker build result
    printf \"\e[1;32m DONE     | : \"$image_2\"\e[0;0m\n\"
}

build_image_3()
{
    printf \"\e[1;33m BUILDING | : \"$image_3\"\e[0;0m\n\"
    sudo docker build worker
    printf \"\e[1;32m DONE     | : \"$image_3\"\e[0;0m\n\"
}

run_image_1()
{
    printf \"\e[1;33m STARTING | : \"$image_1\"\e[0;0m\n\"
    sudo docker-compose up
    flask run --host=0.0.0.0 --port=80
    printf \"\e[1;32m STARTED  | : \"$image_1\"\e[0;0m\n\"
}

run_image_2()
{
    printf \"\e[1;33m STARTING | : \"$image_2\"\e[0;0m\n\" -d
    node result/server.js
    printf \"\e[1;32m STARTED  | : \"$image_2\"\e[0;0m\n\"
}

run_image_3()
{
    printf \"\e[1;33m STARTING | : \"$image_3\"\e[0;0m\n\"
    printf \"\e[1;32m STARTED  | : \"$image_3\"\e[0;0m\n\"
}

build_image_1
build_image_2
build_image_3

run_image_1
run_image_2
run_image_3
    " > builder
    chmod +x builder

    printf "Launcher builder\n"
}

init_stopper()
{
    printf "Creating stopper...\n"

    echo "#!/bin/bash

ids_list=ids.conf
images_list=images.conf

sudo docker ps -aq > \$ids_list
sudo docker images -q > \$images_list

input=\$ids_list
while IFS= read -r line
do
  sudo docker stop "\$line"
  sudo docker rm "\$line"
done < "\$input"

input=\$images_list
while IFS= read -r line
do
  sudo docker rmi "\$line"
done < "\$input"

sudo docker ps -a
    " > stopper.sh
    chmod +x stopper.sh

    printf "Stopper created\n"
}

check_port()
{
    printf "Checking port: $port_1...\n"
    is_free=$(nc localhost $port_1 < /dev/null; echo $?)

    if [[ $is_free == 1 ]]; then
        printf "Port $port_1 is free\n"
    else
        printf "Port $port_1 is already used\n"
    fi
    printf "Port: $port_1 checked\n"

    printf "Checking port: $port_2...\n"
    is_free=$(nc localhost $port_2 < /dev/null; echo $?)

    if [[ $is_free == 1 ]]; then
        printf "Port $port_2 is free\n"
    else
        printf "Port $port_2 is already used\n"
    fi
    printf "Port: $port_2 checked\n"
}

init_docker
init_configuration
check_port
init_launcher
init_stopper