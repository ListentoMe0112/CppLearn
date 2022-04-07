#include <iostream>
using namespace std;
void doTest(){
    
    for (int i = 0; i < 10; i++){
        static int a = 0;
        a ++;
        cout << a << endl;
    }

}

int main(){
    doTest();
}