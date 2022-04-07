#include <iostream>
#include <arpa/inet.h>
using namespace std;
int main(){
    cout << "Prac1" << endl;
    int a;
    const char* ip1 = "205.188.160.121";
    const char* ip2 = "64.12.149.13";
    const char* ip3 = "205.188.146.23";
    cout << inet_pton(AF_INET, ip1, &a) << endl;
    a = htonl(a);
    cout << hex << a << endl;
    cout << inet_pton(AF_INET, ip2, &a) << endl;
    a = htonl(a);
    cout << hex << a << endl;
    cout << inet_pton(AF_INET, ip3, &a) << endl;
    a = htonl(a);
    cout << hex << a << endl;
    return 0;
}