#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/errno.h>
void catch_sigalarm(int signo) {
    printf("catch function");
}
unsigned int mysleep(unsigned int seconds) {
    int ret;
    struct sigaction act, oldact;
    act.__sigaction_u.__sa_handler  = catch_sigalarm;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    ret = sigaction(SIGALRM, &act, & oldact);
    if (ret == -1) {
        perror("sigaction error\n");
        exit(1);
    }
    alarm(seconds);

    ret = pause();
    if (ret == -1 && errno == EINTR) {
        printf("pause success\n");
    }
    ret = alarm(0);
    sigaction(SIGALRM, &oldact, NULL); // 恢复就旧有的信号处理方式
    return ret;
}


int main() {
    while(1) {
        mysleep(3);
        printf("------------\n");
    }
}