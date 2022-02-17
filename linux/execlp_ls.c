#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if(pid == -1) {
        perror("fork error:");
    } else if(pid > 0) {
        sleep(1);
        printf("parent\n");
    } else {
        // execlp("ls", "ls", "-l", "-a", "NULL");
        char * argv[] = {"ls", "-l", "-a", NULL};
        execvp("ls", argv);
    
    }
    return 0;
}