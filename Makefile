
build:
	gcc $(shell find . -name '*.c') -o main

run:
	./main