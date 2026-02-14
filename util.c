#include "util.h"
#include <string.h>
#include <stdio.h>

int input_server_msg(char * buffer,int buf_size)
{
    printf("Eneter message: ");

    if (fgets(buffer,buf_size,stdin) == NULL)
    {
        perror("Input error\n");
        return 0;
    }

    size_t size = strlen(buffer);

    if (size > 0 && buffer[size-1] == '\n')
    {
        buffer[size-1] = '\0';
    }
    return 1;
}