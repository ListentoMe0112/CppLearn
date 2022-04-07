#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

using namespace  std;

void mmapcopy(int fd, int size){
    char* bufp = static_cast<char*> (mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0));
    write(1, bufp, size);
    munmap(bufp, size);
    return;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("usage: %s <filename>\n", argv[0]);
    }

    struct stat stat;

    int fd = open(argv[1], O_RDONLY, 0);

    fstat(fd, &stat);

    mmapcopy(fd, stat.st_size);
    return 0;
}