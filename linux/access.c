#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char * argv[]) {
    if(argc < 2) {
        printf("a.out filename\n");
        exit(1);
    }
    int ret = access(argv[1], W_OK);
    if(ret == -1) {
        perror("access");
        exit(1);
    }
    printf("you have write access to this file\n");
    return 0;
}