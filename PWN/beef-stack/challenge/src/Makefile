# Compile
beef-stack: beef-stack.c
	gcc -fno-stack-protector -z execstack -o beef-stack beef-stack.c
# Clean
clean:
	rm -f beef-stack
# Run
run: beef-stack
	./beef-stack

# Command: make