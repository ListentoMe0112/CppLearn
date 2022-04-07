#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>
using std::vector;
using std::array;
using std::endl;
using std::cin;
using std::cout;
using std::string;
const int ASIZE = 500000;
long get_a_target_long(){
    long target = 0;
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    return target;
}

string get_a_target_string(){
    long target = 0;
    char buf[10];
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareLongs(const void* a, const void* b){
    return (*(long*) a - *(long*)b);
}

int compareStrings(const void* a, const void* b){
    if (*(string*)a > *(string*)b) return 1;
    else if (*(string*)a > *(string*)b) return 01;
    else return 0;
}

void test_array(){
    cout << "\ntest_array().............\n";
    array<long, ASIZE> c;
    clock_t timeStart = clock();
    for (long i = 0; i <ASIZE; i++){
        c[i] = rand();
    }

    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "array.size() = " << c.size() << endl;
    cout << "array.front() = " << c.front() << endl;
    cout << "array.back() = " << c.back() << endl;
    cout << "array.data() = " << c.data() << endl;
    long target = get_a_target_long();
    timeStart = clock();
    qsort(c.data(), ASIZE, sizeof(long), compareLongs);
    long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
    cout << "qsort() + bsearch(), milli-seconds : " << (clock() - timeStart) << endl;
    if (pItem != NULL)
        cout << "found, " << *pItem << endl;
    else
        cout << "not found! " << endl; 
}

void test_vector_push(){
    cout << "\ntest_vector().............\n";

    vector<long> c;
    clock_t timeStart = clock();

    for (long i = 0; i <ASIZE; i++){
        c.push_back(rand());
    }

    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "vector.size() = " << c.size() << endl;
    cout << "vector.capacity() = " << c.capacity() << endl;
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl;
    cout << "vector.data() = " << c.data() << endl;

    long target = get_a_target_long();
    timeStart = clock();

    qsort(c.data(), ASIZE, sizeof(long), compareLongs);

    long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);

    cout << "qsort() + bsearch(), milli-seconds : " << (clock() - timeStart) << endl;
    if (pItem != NULL)
        cout << "found, " << *pItem << endl;
    else
        cout << "not found! " << endl; 
}

void test_vector_empl(){
    cout << "\ntest_vector().............\n";

    vector<long> c;
    clock_t timeStart = clock();

    for (long i = 0; i <ASIZE; i++){
        c.emplace_back(rand());
    }

    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "vector.size() = " << c.size() << endl;
    cout << "vector.capacity() = " << c.capacity() << endl;
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl;
    cout << "vector.data() = " << c.data() << endl;

    long target = get_a_target_long();
    timeStart = clock();

    qsort(c.data(), ASIZE, sizeof(long), compareLongs);

    long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);

    cout << "qsort() + bsearch(), milli-seconds : " << (clock() - timeStart) << endl;
    if (pItem != NULL)
        cout << "found, " << *pItem << endl;
    else
        cout << "not found! " << endl; 
}

int main(){
    // test_array();
    test_vector_push();
    test_vector_empl();
    return 0;
}