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
    // We check if the path is a directory
    struct stat stat_buf;
    if (stat(path, &stat_buf) == -1)
    {
        perror("GET: File information");
        exit(1);
    }
    if(S_ISDIR(stat_buf.st_mode))
    {
        perror("You Entered a path to directory");
        exit(1);
    }

    int fd = open(path, O_RDONLY);
    if (!fd)
    {
        perror("OPEN: Cannot open file");
        exit(1);
    }

    // We read the contents
    if (!read(fd, buffer, BUF_SIZE))
    {
        perror("READ: Cannot Read Data");
        exit(1);
    }
}