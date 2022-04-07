#include <iostream>
#include <arpa/inet.h>
#include "../csapp.h"
using namespace std;
int main(int argc, char* argv[]){
    struct in_addr inaddr;
    uint32_t addr;
    char buf[MAXBUF];
    if (argc != 2){
        fprintf(stderr, "usage: %s <dd pre>\n", argv[0]);
        exit(0);
    }
    sscanf(argv[1], "%s", buf);

    if (!inet_pton(AF_INET, buf, &inaddr.s_addr)){
        unix_error("inet_ntop");
    }

    printf("%x\n", ntohl(inaddr.s_addr));
    return 0;
}