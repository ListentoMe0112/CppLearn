#include <iostream>
/*
    set_new_handler能够安装new-handler  
*/
void outOfMem(){
    std::cerr << "Unable to satisfy request for memory\n";
    std::abort();
}

int main(){
    std::set_new_handler(outOfMem);
    int* pBigDataArray = new int[1000000000000000000L];
    return 0;
}