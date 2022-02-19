#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {
    if(argc < 2) {
        printf("./a.out filename\n");
        exit(1);
    };
    struct stat st;
    int ret = stat(argv[1], &st);
    // lstat 是对于软链接 不穿透
    if(ret == -1) {
        perror("stat");
        exit(1);
    }
    int size = (int)st.st_size;
    printf("file size = %d\n", size);
    return 0;
}