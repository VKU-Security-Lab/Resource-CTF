#!/bin/sh

BINARY=/leak-char/leak-chars

while :; do
    socat -dd -T60 tcp-l:1337,reuseaddr,fork,keepalive,su=nobody exec:$BINARY,stderr
done