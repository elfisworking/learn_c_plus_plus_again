#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main() {
    int fd = open("mytest.txt", O_CREAT |  O_RDWR, 0644);
    if(fd < 0) {
        perror("open error");
        exit(1);
    }
    char *p = NULL;
    int len = ftruncate(fd, 4);
    p = (char *)mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if( p == MAP_FAILED) {
        perror("mmp error:");
    }
    strcpy(p, "abc");
    munmap(p, len);
    close(fd);


}