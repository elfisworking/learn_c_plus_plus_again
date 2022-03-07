CC = gcc
CCFLAGS = -std=gnu99 -Wall -O3 -g -DNDEBUG -pthread
LDFLAGS = -lpthread -pthread
epoll-server: utils.c epoll-server.c
	$(CC) $(CCFLAGS) $^ -o $@ $(LDFLAGS)