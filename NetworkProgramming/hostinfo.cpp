#include <iostream>
#include <arpa/inet.h>
#include "../csapp.h"

int main(int argc, char* argv[]){
    struct addrinfo *p, *listp, hints;
    char buf[MAXBUF];
    //struct sockaddr_in* sockp;
    int rc, flags;

    if (argc != 2){
        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
        return 0;
    }
    /* Get a list of addrinfo records */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
    }

    /* Walk the list and dispay each IP address */
    flags = NI_NUMERICHOST; /* Display address string instead of domain name */
    for (p = listp; p; p = p->ai_next){
        Getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        // const char *inet_ntop (int __af, const void *__restrict __cp,
			      // char *__restrict __buf, socklen_t __len)
        // sockp = (struct sockaddr_in*)p->ai_addr;
        // Inet_ntop(p->ai_family, &(sockp->sin_addr),  buf, MAXLINE);
        printf("%s\n", buf);
    }

    Freeaddrinfo(listp);
    return 0;
}