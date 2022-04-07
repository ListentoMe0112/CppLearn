#include <iostream>

int main(){
    printf("Call Main\n");
    exit(0);
}

extern "C"
int blabla(){
    printf("Yes, It works!\n");
    main();
    exit(0);
}

