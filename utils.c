#include <stddef.h>
#include "headers/utils.h"

char* get_path(int argc, char* argv[]){
    int path_index = 1;
    if(argc != 2)
    {
        return NULL;
    }
    for(int i=0; i<argc; i++){
        if(i == path_index){
            return argv[i];
        }
    }
}