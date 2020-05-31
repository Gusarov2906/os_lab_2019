CC=gcc
CCFLAGS=-I.

all : client server

client : MultModuloLib.o MultModuloLib.h
	$(CC) -o client MultModuloLib.o client.c -lpthread $(CCFLAGS)

server : MultModuloLib.o MultModuloLib.h
	$(CC) -o server MultModuloLib.o server.c -lpthread $(CCFLAGS)

MultModuloLib.o : MultModuloLib.h
	$(CC) -o MultModuloLib.o -c MultModuloLib.c $(CCFLAGS)

clean :
	rm MultModuloLib.o
