#!/bin/bash

# Build docker image
docker build -t n3wb1e-pwn .

# Run docker container
docker run -d -p 10010:1337 --name n3wb1e-pwn n3wb1e-pwn
