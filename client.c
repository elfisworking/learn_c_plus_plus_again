#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define SERV_IP  "127.0.0.1"
#define SERV_PORT 6666
int main () {
    int cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);
    socklen_t addrlen = sizeof(serv_addr);
    connect(cli_fd, (struct sockaddr * )&serv_addr, addrlen);
    char buf[BUFSIZ];
    while (1) {
        fgets(buf, sizeof(buf), stdin);
        write(cli_fd, buf, strlen(buf));
        int n = read(cli_fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
    }
    close(cli_fd);
}