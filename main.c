#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "headers/constants.h"
#include "headers/utils.h"
#include "headers/reader.h"

int main(int argc, char *argv[])
{
    // Handle window resize
    signal(SIGWINCH, window_resize_signal_handle);
    char buffer[BUF_SIZE];
    char *path = get_path(argc, argv);
    if (path == NULL)
    {
        perror("PATH: Enter Valid Path");
        exit(EXIT_FAILURE);
    }
    clear();
    get_data_from_file(path, buffer);
    printf("%s\n", buffer);
    fflush(stdout);
    return 0;
}