#include <unistd.h>
#include "./headers/constants.h"

int main(){
    char buf[] = "Hello World\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    return 0;
}