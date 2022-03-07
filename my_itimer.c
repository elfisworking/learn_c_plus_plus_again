#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signalHandler(int signo) {
    switch (signo)
    {
    case SIGALRM:
        printf("caught the SIGALRM signal\n");
        break;
    }
}

int main() {
    signal(SIGALRM, signalHandler);
    struct itimerval new_value, old_value;
    new_value.it_value.tv_sec = 0;
    new_value.it_value.tv_usec = 1;
    new_value.it_interval.tv_sec = 0;
    new_value.it_interval.tv_usec = 200000;
    int i = setitimer(ITIMER_REAL, &new_value, &old_value);
    printf("state is %d\n", i);
    while(1) {

    }
    return 0;
}