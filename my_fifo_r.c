#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define FIFO_NAME "testfifo"
#define BUF_SIZE 1024

int main() {
    int fd;
    char buf[BUF_SIZE];
    fd = open(FIFO_NAME, O_RDONLY);
    read(fd, buf, BUF_SIZE);
    printf("%s\n", buf);
    close(fd);
    return 0;
}