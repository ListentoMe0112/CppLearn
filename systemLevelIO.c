#include "csapp.h"
#include <unistd.h>
int main(void){
    char c;
    while (Read(STDIN_FILENO, &c, 1)){
        Write(STDOUT_FILENO, &c, 1);
    }
    const char* end = "Finished";
    Write(STDOUT_FILENO, end, sizeof(end));
    return 0;
}