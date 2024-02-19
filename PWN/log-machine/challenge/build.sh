#!/bin/bash

# Build docker image
docker build -t log-machine .

# Run docker container
docker run -d -p 10005:1337 --name log-machine log-machine
