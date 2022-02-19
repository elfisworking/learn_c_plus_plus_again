#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("english.txt",O_RDONLY);
    if(fd == -1) {
        perror("open file");
        exit(1);
    }
    int fd1 = open("newfile.txt", O_CREAT | O_WRONLY, 0777);
    if(fd == -1) {
        perror("open1");
        exit(1);
    }
    char buf[2048];
    int count = read(fd, buf, sizeof(buf));
    if(count == -1) {
        perror("read");
        exit(1);
    }
    while(count != 0 ) {
        int ret = write(fd1, buf, count);
        printf("write bytes %d\n", ret);
        count = read(fd, buf, sizeof(buf));
    }
    close(fd);
    close(fd1);
    exit(1);
}