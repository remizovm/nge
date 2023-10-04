.PHONY: build

CC=gcc

build:
	$(CC) main.c -lSDL2
