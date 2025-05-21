CC = gcc
CFLAGS = -Wall -Iinclude

SRC = server/server.c server/logger.c
OUT = filters_server

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)