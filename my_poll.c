#include <sys/socket.h>
#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <poll.h>
#include <signal.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAXLINE 5
#define OPEN_MAX 1024
#define SA struct sockaddr
int main() {
    int listenfd, connfd, sockfd, i, maxi;
    int nready;
    socklen_t clilen;
    ssize_t n;
    char buf[MAXLINE];
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in servaddr, cliaddr;
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket() erro!\n");
        exit(0);
    }
    bzero(&servaddr, 0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if(bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind() error");
        exit(0);
    }
    if(listen(listenfd, 5) < 0) {
        perror("listen fail");
        exit(0);
    }
    client[0].fd = listenfd;
    client[0].events = POLLIN;
    for(int i = 1; i < OPEN_MAX; i++) {
        client[i].fd = -1;
    }
    maxi = 0;
    printf("begin listen\n");
    while(1) {
        nready = poll(client, maxi + 1, -1);
        if(client[0].revents && POLLIN) {
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (SA *)&cliaddr, &clilen);
            if(connfd < 0) {
                continue;
            }
            printf("%d\n", connfd);
            for( i = 1; i < OPEN_MAX; i++) {
                if(client[i].fd == -1) {
                    client[i].fd = connfd;
                    client[i].events = POLLIN;
                    break;
                }
            }
            if(i == OPEN_MAX) {
                printf("too many clients");
                exit(0);
            }
            if(i > maxi) {
                maxi = i;
            }
            if(--nready <= 0) {
                continue;
            }
        }
        for(i = 1; i < OPEN_MAX; i++) {
        if(client[i].fd < 0) {
            continue;
        }
        if(client[i].revents & POLLIN | POLLERR) {
            if((n = read(client[i].fd, buf, MAXLINE)) < 0) {
                if(errno = ECONNRESET) {
                    close(sockfd);
                    client[i].fd = -1;
                } else {
                    printf("read error\n");
                }
            } else if(n == 0) {
                close(sockfd);
                client[i].fd = -1;
            } else {
                write(client[i].fd, buf, n);
            }
            if(--nready < 0) {
                break;
            }
        }
    }

    }

}