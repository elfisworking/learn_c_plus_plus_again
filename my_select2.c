#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
static void usage(const char * proc) {
    printf("Usage : %s [Local_ip] [local_port]\n", proc);
}

int readfds[sizeof(fd_set) * 8];
char buf[1024];
int startup(char * ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket:");
        exit(1);
    }
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = inet_addr(ip);
    if(bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0) {
        perror("bind:");
        exit(2);
    }
    if(listen(sock, 5) < 0) {
        perror("listen:");
        exit(3);
    }
    return sock;
}

int main(int argc, char * argv[]) {
    if(argc != 3) {
        return 4;
    }
    int listen_scok = startup(argv[1], atoi(argv[2]));
    int i = 1;
    int num = sizeof(fd_set) * 8;
    readfds[0] = listen_scok;
    for(; i < num; i++) readfds[i] = -1;
    fd_set wfds, rfds;
    while(1) {
        int maxfd = -1;
        FD_ZERO(&rfds);
        for(i = 0; i < num; i++) {
            if(readfds[i] != -1) {
                FD_SET(readfds[i], &rfds);
            }
            maxfd = maxfd < readfds[i] ? readfds[i] : maxfd;
        }
        struct timeval time = {1, 0};
        int  n = select(maxfd + 1, &rfds, &wfds, NULL, &time);
        switch (n)
        {
        case 0:
            printf("time out\n");
            break;
        case -1:
            break;
        default:
        for(int i = 0; i < num; i++) {
            if(i == 0 && FD_ISSET(readfds[i], &rfds)) {
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                int client_sock = accept(listen_scok, (struct sockaddr *)&client, &len);
                if(client_sock < 0) {
                    perror("accept:");
                    continue;
                } 
                for(int j = 1; j < num; j++) {
                    if(readfds[j] == -1) {
                        readfds[j] = client_sock;
                        break;
                    }
                    if(j > num) {
                        printf("readfds is full\n");
                        exit(5);
                    }
                }
            }
            if(i != 0 && FD_ISSET(readfds[i], &rfds)) {
                int s = read(readfds[i], buf, sizeof(buf) - 1);
                if(s < 0) {
                    perror("read");
                    return 6;
                }
                else if(s == 0) {
                    printf("client quit\n");
                    readfds[i] = -1;
                    close(readfds[i]);
                    continue;
                } else {
                    buf[s] = 0;
                    printf("client#: %s\n", buf);
                    fflush(stdout);
                    write(readfds[i], buf, strlen(buf));
                }
            }
        }
            break;
        }
    }
}