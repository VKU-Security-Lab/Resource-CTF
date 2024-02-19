# Compile
more-beef-stack: main.c
	gcc -m32 -fno-stack-protector -no-pie -z execstack -o more-beef-stack main.c
# Clean
clean:
	rm -f more-beef-stack
# Run
run: more-beef-stack
	./more-beef-stack

# Command: make