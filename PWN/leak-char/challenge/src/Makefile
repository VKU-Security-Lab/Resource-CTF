# Compile
leak-chars: main.c
	gcc -fno-stack-protector -z execstack -o leak-chars main.c
# Clean
clean:
	rm -f leak-chars
# Run
run: leak-chars
	./leak-chars

# Command: make