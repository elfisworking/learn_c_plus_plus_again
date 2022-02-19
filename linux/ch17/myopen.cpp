#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int fd;
    // fd = open("no_exist", O_RDONLY);
    // if(fd == -1) {
    //     perror("open file");
    //     exit(0);
    // }
    // close(fd);
    fd = open("myhello", O_RDWR | O_CREAT | O_EXCL, 0777);
    if(fd == -1) {
        perror("open file");
        exit(1);
    }
    printf("f = %d\n", fd);
    int ret = close(fd);
    printf("ret = %d\n", ret);
    return 0;

}