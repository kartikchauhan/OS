#include<iostream>

using namespace std;

namespace n1 {
    int x = 10;

    void print() {
        cout << "x in namespace n1 is " << x << endl;
    }
}

namespace n2 {
    int x = 20;

    void print() {
        cout << "x in namespace n2 is " << x << endl;
    }
}

int main() {
    n1::print();
    n2::print();
    
    return 0;
}