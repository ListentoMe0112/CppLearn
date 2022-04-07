#include <iostream>
#include <map>
#include <string>
using namespace std;

template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x+y){
    return x + y;
};




class UnNamedLocalFunction{
    int localVal;
public:
    UnNamedLocalFunction(int var) : localVal (var){};
    bool operator()(int val){
        return val == localVal;
    };
};

int main(){
    int id = 0;
    auto f1 = [id]() mutable -> int{
        cout << "id: " << id << endl;
        ++id;
        static int y = 1;
        return id;

    };
    id = 100;
    auto f2 = [&id]()  {
        cout << "id: " << id << endl;
        ++id;
    };
    f1();
    f1();
    f2();
    f2();
    int toBeFound = 5;
    auto lambda1 = [toBeFound](int val) {return val == toBeFound;};
    UnNamedLocalFunction lambda2(toBeFound);
    bool b1 = lambda1(5);
    bool b2 = lambda2(5);
    cout << b1 << endl;
    cout << b2 << endl;
    return 0;   
} 
