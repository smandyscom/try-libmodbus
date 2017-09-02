all: 
	gcc -g -c main.c
	gcc -g -v main.o /usr/local/lib/libmodbus.dylib -o main