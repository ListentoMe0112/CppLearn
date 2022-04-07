#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

struct MyPair{
    double a, b;
    double multiply(){
        return a*b;
    }
};

double myDivide(const double& a, const double& b){
    return a / b;
}
int main(){
    auto fn1 = bind(myDivide, _1, 2);
    cout << fn1(3) << endl;
    auto fn2 = bind<int>(myDivide, _1, 2);
    cout << fn2(3) << endl;
    auto fn3 = bind(&MyPair::multiply, _1);
    MyPair m1 {10, 20};
    cout << fn3(m1) << endl;
    auto fn4 = bind(&MyPair::a, _1);
    cout << fn4(m1) << endl;

    vector<int> v {15, 37, 94, 50, 73, 58,98};
    auto fn_ = bind(less<int>(), _1, 50);
    cout << count_if(v.begin(), v.end(), fn_) << endl;
    cout << count_if(v.begin(), v.end(), bind(less<int>(),_1, 50)) << endl;
    return 0;
}