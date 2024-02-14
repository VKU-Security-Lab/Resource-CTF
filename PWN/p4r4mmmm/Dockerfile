FROM ubuntu:latest

RUN apt-get update && apt-get install socat libc6-i386 libc6 -y && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /p4r4mmmm

COPY /src/p4r4mmmm .
COPY /src/flag.txt .
COPY entry.sh /

RUN chmod 440 /p4r4mmmm/flag.txt
RUN chmod +x /entry.sh
RUN chmod +x /p4r4mmmm/p4r4mmmm

CMD ["/entry.sh"]