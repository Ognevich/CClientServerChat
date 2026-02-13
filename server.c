#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include "config.h"

int main(int argc,char* argv[])
{

    int server_fd;
    int cleint_fd;
    struct sockaddr_in address;
    char buffer[BUFF_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Server descriptor failed\n");
        return 1;
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) != 0) 
    {
        perror("Bind failed\n");
        return 1;
    }

    if (listen(server_fd,3) != 0)
    {
        perror("Listen failed\n");
        return 1;
    }
    
    printf("Waiting client...\n");
    cleint_fd = accept(server_fd,NULL,NULL);
    if (cleint_fd < 0)
    {
        perror("Client descriptor failed\n");
        return 1;
    }

    if (read(cleint_fd, buffer, BUFF_SIZE) < 0)
    {
        perror("Read failed\n");
        return 1;
    }

    printf("Client: %s\n", buffer);

    if (send(cleint_fd,"Hello from server", 17, 0))
    {
        perror("Send failed\n");
        return 1;
    }

    close(server_fd);
    close(cleint_fd);

    return 0;
}