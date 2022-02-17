#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

typedef struct Info {
    char fromFile[255];
    char toFile[255];
    int num;
    int length;
    int offset;
    int filesize;
}Info;

void * doThread(void * arg) {

}

int main(int argc, char * argv[]) {
    pthread_t * tid;
    Info * info;
    info = (Info *)malloc(5 * sizeof(Info));
    tid = (pthread_t *)malloc(5 * sizeof(pthread_t));
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open src failed:");
        exit(errno);
    }
}