#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "config.h"

int main(int argc,char* argv[])
{

    int server_fd;
    int cleint_fd;
    struct sockaddr_in address;
    char buffer[BUFF_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htonl(PORT);

    bind(server_fd, (struct sockaddr*) &address, sizeof(address));

    printf("Hello world\n");

    return 0;
}