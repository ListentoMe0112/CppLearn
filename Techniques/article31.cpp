#include <exception>
#include <iostream>
#include <string>
using namespace std;
class TooManyObjects : public exception{
public:
    TooManyObjects(string s){
        error = s;
        // cout << "Construct Error: "<<s << endl;
    }   

    virtual const char* const what()  {
        // cout << "In what Function "<< error << endl;
        return error.c_str();
    }

    string error;
};

template<typename T>
class Counted{
public:
    static int objectCount(){
        return numObjects;
    }
protected:
    Counted();
    Counted(const Counted<T>& rhs);
    ~Counted(){ -- numObjects ;}
private:
    static int numObjects;
    static const size_t maxObjects = 1;
    void init();
};


template<typename T>
Counted<T>::Counted()
{
    // cout << "Counted Construction Bein" << endl;
    init();
}

template<typename T>
Counted<T>::Counted(const Counted<T>& rhs)
{init();}

template<typename T>
void Counted<T>::init(){
    if (numObjects >= maxObjects) throw(TooManyObjects("Too Many Objects"));
    ++numObjects;
    // cout << numObjects << endl;
}

class Printer : private Counted<Printer>{
public:
    static Printer* makePrinter(){
        Printer* p = new Printer();
        // cout << objectCount() << endl;
        return p;
    }
    static Printer* makePrinter(const Printer& rhs){
        Printer* p = new Printer();
        return p;
    };
    ~Printer();
    void submitJob(){
        cout << "Submit Job" << endl;
    }
    void reset(){
        cout << "Reset" << endl;
    }
    void performSelfTest(){
        cout << "PerformSelfTest" << endl;
    }
    using Counted<Printer>::objectCount;
private:
    Printer(){};
    Printer(const Printer& rhs){};
};

template<typename T>
int Counted<T>::numObjects = 0;

int main(){
    try{
        Printer* p1 = Printer::makePrinter();
        // Printer* p2 = Printer::makePrinter();
    }catch(TooManyObjects& e){
        cout << e.what() << endl;
    }
    return 0;
}