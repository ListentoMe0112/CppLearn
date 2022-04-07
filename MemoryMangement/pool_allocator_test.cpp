#include <iostream>
#include <ext/pool_allocator.h>

using namespace std;
template <typename Alloc>
void cookie_test(Alloc alloc, size_t n){
    typename Alloc::value_type *p1, *p2, *p3;
    p1 = alloc.allocate(n);
    p2 = alloc.allocate(n);
    p3 = alloc.allocate(n);
    cout << "p1=" << p1 << "\t" << "p2=" << p2 << "\t" << "p3=" << p3 << endl;
}

int main(){
    cout << "pool_alloc<int>" << endl;
    cookie_test(__gnu_cxx::__pool_alloc<int>(), 1);
    cout << "std::alloc" << endl;
    cookie_test(std::allocator<int>(), 1);
    return 0;
}