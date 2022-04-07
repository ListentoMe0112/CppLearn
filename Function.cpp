class Base1{
public:
    Base1(){};
    virtual ~Base1(){};
    virtual void speakClearly(){};
    virtual Base1 *clone() const{};
protected:
    float data_Base1;
};

class Base2{
public:
    Base2(){};
    virtual ~Base2(){};
    virtual void mumble(){};
    virtual Base2* clone() const{};
protected:
    float data_Base2;
};

class Derived1 : public virtual Base1, public virtual Base2{
public:
    Derived1(){};
    virtual ~Derived1(){};
protected:
    float data_Derived1;
};

class Derived2 : public  Base1, public virtual Base2{
public:
    Derived2(){};
    virtual ~Derived2(){};
protected:
    float data_Derived2;
};

#include <iostream>
using namespace std;

int main(){

    cout << sizeof(Base1) << endl;
    cout << sizeof(Base2) << endl;
    cout << sizeof(Derived1) << endl;
    cout << sizeof(Derived2) << endl;
    return 0;
}