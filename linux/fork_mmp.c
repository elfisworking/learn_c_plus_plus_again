#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
int var = 100;

int main() {
    int *p;
    pid_t pid;
    int fd;
    fd = open("temp", O_CREAT |O_RDWR |O_TRUNC, 0644);
    if(fd < 0) {
        perror("open error");
        exit(1);
    }
    unlink("temp");
    ftruncate(fd, 4);
    p = (int *)mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED) {
        perror("mmp error");
        exit(1);
    }
    close(fd);
    pid = fork();
    if(pid == 0) {
        *p = 2000;
        var = 1000;
        printf("child *p = %d, var = %d\n", *p, var);
    } else {
        sleep(1);
        printf("parent, *p = %d, var = %d\n", *p, var);
        wait(NULL);
        munmap(p, 4);
    }
    return 0;
}