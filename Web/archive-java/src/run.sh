#!/bin/bash

random_string=$(head /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 8 | head -n 1)

echo "VSL{Z1p_4rch1v3_un54f3_4s_y0u_7h1nk}" > "/$random_string-flag.txt"

exec /usr/local/tomcat/bin/catalina.sh run
