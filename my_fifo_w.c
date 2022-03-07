#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

#define FIFO_NAME "testfifo"

int main() {
    int fd;
    char buf[] = "this is a test";
    mkfifo(FIFO_NAME, S_IFIFO | 0666);
    fd = open(FIFO_NAME, O_RDWR);
    write(fd, buf, strlen(buf) + 1);
    close(fd);
    unlink(FIFO_NAME);
    while(1) {

    }
    return 0;
}