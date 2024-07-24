#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "headers/reader.h"
#include "headers/constants.h"

void get_data_from_file(char *path, char *buffer)
{
    // We check if the path is a directory
    struct stat stat_buf;
    if (stat(path, &stat_buf) == -1)
    {
        perror("GET: File information");
        exit(EXIT_FAILURE);
    }
    if (S_ISDIR(stat_buf.st_mode))
    {
        perror("You Entered a path to directory");
        exit(EXIT_FAILURE);
    }

    int fd = open(path, O_RDONLY);
    if (!fd)
    {
        perror("OPEN: Cannot open file");
        exit(EXIT_FAILURE);
    }

    // We read the contents
    if (!read(fd, buffer, BUF_SIZE))
    {
        perror("READ: Cannot Read Data");
        exit(EXIT_FAILURE);
    }
}

// TODO: Make it like an editor and add line numbers and fill remaining area with empty text
struct winsize get_editor_size()
{
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return ws;
}

void window_resize_signal_handle(int signum)
{
    struct winsize size = get_editor_size();
    printf("\nCols = %d Rows = %d\n", size.ws_col, size.ws_row);
}