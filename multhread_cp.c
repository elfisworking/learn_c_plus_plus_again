// 多线程拷贝
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct  Info
{   
    char fromFile[255];
    char toFile[255];
    int num;
    int length;
    int offset;
    int filesize;
}Info;

void * doThread(void * arg) {
    Info * info = (Info *)arg;
    int fin = open(info->fromFile, O_RDONLY);
    int fout = open(info->toFile, O_RDWR);
    printf("this %d thread begin copy\n", info->num);
    char * s_addr = (char *)mmap(NULL, info->filesize, PROT_READ, MAP_SHARED, fin, 0);
    char * d_addr = (char *)mmap(NULL, info->filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fout, 0);
    //每个线程负责拷贝文件的不同部分在这里就体现出来了，拷贝的长度通过参数得知
    memcpy(d_addr+info->offset,s_addr+info->offset,info->length);
    printf("The %d thread close copy\n", info->num);
    munmap(d_addr, info->length);
    munmap(s_addr, info->length);
    return NULL;


    
}

int main(int argc, char * argv[]) {
    pthread_t tid[5];
    Info info[5];
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        perror("open src failed:");
        exit(errno);
    }
    umask(000);
    int fd2 = open(argv[2], O_RDWR | O_CREAT, 0660);
    if(fd < 0) {
        perror("open des failed:");
        exit(errno);
    }
    int fileSize = lseek(fd, 0, SEEK_END);
    ftruncate(fd2, fileSize);
    int offset = fileSize / 5;
    for(int i = 0; i < 4; i++) {
        info[i].num = i;
        strcpy(info[i].fromFile, argv[1]);
        strcpy(info[i].toFile, argv[2]);
        info[i].length = offset;
        info[i].offset = i * offset;
        info[i].filesize = fileSize;
    }
    info[4].num = 4;
    strcpy(info[4].fromFile, argv[1]);
    strcpy(info[4].toFile, argv[2]);
    info[4].length = fileSize - 4 * offset;
    info[4].offset = 4 * offset;
    info[4].filesize = fileSize;
    for(int i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, doThread, &info[i]);
    }
    for(int  i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}