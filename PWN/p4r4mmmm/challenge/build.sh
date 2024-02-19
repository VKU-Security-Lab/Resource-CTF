#!/bin/bash

# Build docker image
docker build -t p4r4mmmm .

# Run docker container
docker run -d -p 10002:1337 --name p4r4mmmm p4r4mmmm
