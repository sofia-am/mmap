CC = gcc
CFLAGS = -Wall -pedantic -g -Werror
OBJS = bin
SRC = src

all: mkdir main

mkdir:
	mkdir -p $(OBJS) 	$(SRC)

main: $(OBJS)/main.o 
	$(CC) -o $@ $(OBJS)/main.o 

$(OBJS)/main.o: $(SRC)/main.c
	$(CC) -c $(SRC)/main.c $(CFLAGS) -o $@

clean:
	rm -rf $(OBJS)/*.o  main