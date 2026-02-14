#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "config.h"
#include "util.h"

int main (int argc, char * argv[])
{

    int sock_fd;
    struct sockaddr_in sock_addr;
    char buffer[BUFF_SIZE] = {0};

    sock_fd = socket(AF_INET, SOCK_STREAM,0);
    if (sock_fd < 0)
    {
        perror("Descriptor failed\n");
        return 1;
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(PORT);
    inet_pton(AF_INET,"127.0.0.1", &sock_addr.sin_addr);

    if (connect(sock_fd,(struct sockaddr*)&sock_addr, sizeof(sock_addr)) < 0)
    {
        perror("Connection to server failed\n");
        return 1;
    }

    char send_buffer[MESSAGE_SIZE];
    input_server_msg(send_buffer,MESSAGE_SIZE);


    if (send(sock_fd,send_buffer,sizeof(send_buffer), 0) < 0)
    {
        printf("Send failed\n");
        return 1;
    }

    if (read(sock_fd,buffer, BUFF_SIZE) < 0)
    {
        printf("Read failed\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    close(sock_fd);

    return 0;
}