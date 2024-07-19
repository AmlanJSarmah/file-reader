#include <stdio.h>
#include "headers/constants.h"
#include "headers/utils.h"

int main(int argc, char *argv[])
{
    char* path = get_path(argc, argv);
    printf("\n%s\n", path);
    return 0;
}