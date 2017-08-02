CC=gcc
CFLAGS= -Wall -O0

all:
	$(CC) main.c -o main $(CFLAGS)
