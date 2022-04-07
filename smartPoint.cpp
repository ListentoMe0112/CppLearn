#include <iostream>
#include <memory>

int main(){
    
    
    int* a = new int(10);
    std::shared_ptr<int> pi(a);
    std::cout << "use_count() = " << pi.use_count() << " value = " << *pi << std::endl;
    pi.reset();
    std::cout << "use_count() = " << pi.use_count() << " value = " << *pi << std::endl;
}