#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
void mydaemon() {
 pid_t pid, sid;
    pid = fork();
    if(pid == 0) {
        sid = setsid();
        int sof = chdir("/Users/yumin_zhang/");
        if(sof < 0) {
            perror("chdir error");
            exit(1);
        }
        umask(0002);
        close(0);
        int fd = open("/dev/null", O_RDWR);
        dup2(0, STDOUT_FILENO);
        dup2(0, STDERR_FILENO);
        

    } else {
        exit(1);
    }
    
}
int main() {
    mydaemon();
    while(1) {

    }
    return 0;
}
