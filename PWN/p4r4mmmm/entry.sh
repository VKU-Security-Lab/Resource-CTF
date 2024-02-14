#!/bin/sh

BINARY=/p4r4mmmm/p4r4mmmm

while :; do
    socat -dd -T60 tcp-l:1337,reuseaddr,fork,keepalive,su=nobody exec:$BINARY,stderr
done