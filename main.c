#include <stdio.h>
#include <stdlib.h>
#include "headers/constants.h"
#include "headers/utils.h"

int main(int argc, char *argv[])
{
    char *path = get_path(argc, argv);
    if (path == NULL)
    {
        perror("PATH: Enter Valid Path");
        exit(1);
    }
    return 0;
}