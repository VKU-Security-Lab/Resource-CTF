FROM ubuntu:latest

RUN apt-get update && apt-get install socat libc6-i386 libc6 -y && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /log-machine

COPY src/log-machine .
COPY src/flag.txt /
COPY entry.sh /

RUN chmod +x /log-machine/log-machine
RUN chmod +x /entry.sh
RUN chmod 444 /flag.txt
RUN touch /tmp/log.txt
RUN chmod 777 /tmp/log.txt

CMD ["/entry.sh"]