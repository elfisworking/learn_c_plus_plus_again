#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if(pid == 0) {
        close(fd[1]);
        char buf[1024];
        read(fd[0], buf, sizeof(buf));
    }else {
        close(fd[0]);
        char * str = "hello pipe\n";
        write(fd[1], "hello pipe\n", strlen)
    }
    return 0;
}