#include <iostream>
#include <bitset>
using namespace std;

void print(){};

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args){
    cout << firstArg << endl;
    print(args...);
}


/*
    If one or more arguments are pased, the function template is uesd, which by specifying the 
    first argument sparately allows the first argument to print and then recursively calls print()
    for the remaining arguments. To end the recursion, the non-template overload of print() is 
    provided.
*/
template<typename... Types>
void print(const Types&... args){
    cout << "This is another print" << endl;
}


/*
    使用variadic templates 重写 printf
*/

void myPrintf(const char* s){
    while (*s){
        if (*s == '%' && *(++s) != '%'){
            throw std::runtime_error("invalid format string::missing argument");
        }
        std::cout << *s++;
    }
}

template <typename T, typename... Types>
void myPrintf(const char* s, const T& firstArg, const Types&... args){
    while (*s){
        if (*s == '%' && *(++s) != '%'){
            cout << firstArg;
            printf(++s, args...);
            return;
        }
        cout << *s++;
    }
    throw std::logic_error("extra arguments provides to printf");
}


/*
    实现max 使用initializer_list
*/

int maximum(int n){ return n; };

template<typename... Args>
int maximum(int n, Args... args){
    return std::max(n, maximum(args...));
}

int main(){
    print(7.5, "hello", bitset<16>(277), 42);
    int* pi = new int;
    myPrintf("%d, %s %p %f\n", 15, "This is Aec.", pi, 3.1415926535);
    cout << maximum(5,1,23,543,534,6,4556,34,654) << endl;
    return 0;
}

