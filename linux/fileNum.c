#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileNum(const char * root) {
    
    DIR * dir = opendir(root);
    if(dir == NULL) {
        perror("open dir");
        eixt(1);
    }
    struct dirent * p = NULL;;
    char path[1024] = {0};
    int total = 0;
    while(( p = readdir(dir) != NULL)) {
        if(strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0) continue;
        if(p->d_type == DT_DIR) {
            sprintf(path, "%s/%s", root, p->d_name);
            total += getFileNum(path);

        } 
        if(p->d_type == DT_REG) total++;
    }
    close(dir);
    return total;
}

int main(int argc, char * argv[]) {
    if(argc < 2) {
        printf("./a.out dir");
        exit(1);
    }
    int total = getFileNum(argv[1]);
    printf("The number of file is %d\n", total);
    return 0;
}