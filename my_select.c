#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    retval = select(1, &rfds, NULL, NULL, &tv);
    if(retval == -1) {
        printf("select()\n");
    } else if(retval) {
        printf("Data is available now\n");
    } else {
        printf("NO data within five seconds\n");
    }
    return 0;
}