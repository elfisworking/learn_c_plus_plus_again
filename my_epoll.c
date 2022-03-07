#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define SERV_PORT 6667
const char * LOCAL_ADDR = "127.0.0.1";
#define SIZE 1024
char buf[SIZE];
int main(){
    int listensock = socket(AF_INET, SOCK_STREAM, 0);
    if(listensock < 0) {
        perror("socket error");
        exit(0);
    }
    struct sockaddr_in server_addr, client_addr;
    socklen_t len = sizeof(client_addr);
    bzero(&server_addr, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = inet_addr(LOCAL_ADDR);
    int epoll_fd = epoll_create(1);
    struct epoll_event serv_event;
    serv_event.data.fd = listensock;
    serv_event.events = EPOLLIN;
    epoll_ctl(epoll_fd , EPOLL_CTL_ADD, listensock, &serv_event);
    int state;
    state = bind(listensock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(state < 0) {
        perror("bind error");
        exit(1);
    }
    state = listen(listensock, 5);
    if(state < 0) {
        perror("listen error");
        exit(1);
    }
    printf("begin listen\n");
    struct epoll_event events[32];

    while(1) {
        int  ready = epoll_wait(epoll_fd, events, 25, 5);
        if(ready < 0) {
            continue;
        }
        for(int i = 0; i < ready; i++) {
            if(events[i].data.fd == listensock && (events[i].events & EPOLLIN)) {
                int cli_fd = accept(listensock, (struct sockaddr *)&client_addr, &len);
                if(cli_fd < 0) {
                    perror("accept error");
                    exit(1);
                }
                struct epoll_event cli_event;
                cli_event.events = EPOLLIN;
                cli_event.data.fd = cli_fd;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, cli_fd, &cli_event);
                continue;
            }
            if(events[i].events && EPOLLIN) {
                int n = read(events[i].data.fd, buf, SIZE);
                if(n < 0) {
                    perror("read error");
                    close(events[i].data.fd);
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, &events[i]);
                    exit(1);
                } else if (n == 0) {
                    close(events[i].data.fd);
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, &events[i]);
                    continue;
                }
                write(events[i].data.fd, buf, n);
            }
        }
    }
    return 0;
    
}