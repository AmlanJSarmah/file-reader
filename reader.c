#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/reader.h"
#include "headers/constants.h"

void get_data_from_file(char *path, char *buffer)
{
    int fd = open(path, O_RDONLY);
    if (!fd)
    {
        perror("OPEN: Cannot open file");
        exit(1);
    }
    if (!read(fd, buffer, BUF_SIZE))
    {
        perror("READ: Cannot Read Data");
        exit(1);
    }
}