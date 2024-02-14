# Compile
log-machine: main.c
	gcc -m32 -fno-stack-protector -z execstack -o log-machine main.c
# Clean
clean:
	rm -f log-machine
# Run
run: log-machine
	./log-machine

# Command: make