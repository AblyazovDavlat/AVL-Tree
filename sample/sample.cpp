#include <iostream>
#include "Set.h"
using namespace std;

int main(int argc, char** argv) {
    Set set;

    for (int i = atoi(argv[1]) - 1; i >= 0; i--) {
        set.insert(i * 3);
    }
    
    cout << "Size: " << set.size() << endl;

    cout << boolalpha;
    cout << "expect true: " << (bool)set.find(0) << endl;
    cout << "expect true: " << (bool)set.find(297) << endl;
    cout << "expect true: " << (bool)set.find(168) << endl;

    cout << "expect false: " << (bool)set.find(2) << endl;
    cout << "expect false: " << (bool)set.find(299) << endl;
    cout << "expect false: " << (bool)set.find(167) << endl;

    cout << "Deleting 1 element..." << endl;
    set.erase(168);
    cout << "Current size: " << set.size() << endl;
    cout << "Is that element in set: " << (bool)set.find(168) << endl;

    cout << "Try delete it again..." << endl;
    cout << "Expected not 0 returned: " << set.erase(168) << endl; 

    return 0;
}