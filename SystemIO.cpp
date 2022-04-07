#include "csapp.h"
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    struct stat stat;
    char *type, *readok;
    Stat(argv[1], &stat);
    if (S_ISREG(stat.st_mode))
        type = "regular";
    else if (S_ISDIR(stat.st_mode))
        type = "directory";
    else
        type = "other";
    if ((stat.st_mode & S_IRUSR))
        readok = "ok";
    else
        readok = "no";
    printf("Type: %s and read is %s\n", type, readok);
    return 0;
}