#!/bin/bash

ids_list=ids.conf
images_list=images.conf

sudo docker ps -aq > $ids_list
sudo docker images -q > $images_list

input=$ids_list
while IFS= read -r line
do
  sudo docker stop $line
  sudo docker rm $line
done < $input

input=$images_list
while IFS= read -r line
do
  sudo docker rmi $line
done < $input

sudo docker ps -a
    
