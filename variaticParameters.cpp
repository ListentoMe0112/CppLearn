#include <iostream>
using namespace std;

void func2()
{
}
 
template <typename T, typename... U>
void func2(T v, U... args)
{
    // std::cout << typeid (U).name ()
	cout << v << endl;
	func2(args...);
}
 
template <typename... T>
void func1(T... args)
{
    // cout << args... << endl;
	cout << sizeof...(T) << endl;
	cout << sizeof...(args) << endl;
    func2((2+args)...);
}
 

 
int main()
{
    func1(1,2,3);
 
	system("pause");
	return 0;
}