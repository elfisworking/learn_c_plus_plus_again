#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <ctype.h>

#define SERVE_PORT 6666
#define SERVE_IP "127.0.0.1"
int main () {
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVE_PORT);
    serv_addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    bind(serverfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(serverfd, 128);
    int clientfd;
    struct sockaddr_in clie_addr;
    socklen_t cli_addr_len = sizeof(clie_addr);
    clientfd = accept(serverfd, (struct sockaddr *)&clie_addr, &cli_addr_len);
    char buf[BUFSIZ];
    while (1) {
        int n = read(clientfd, buf, sizeof(buf));
        for(int i = 0; i < n; i++) {
            buf[i] = toupper(buf[i]);
        }
    write(clientfd, buf, n);
    }
    close(clientfd);
    close(serverfd);

}