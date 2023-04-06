// Critical section problem or Race condition

#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int counts = 0;

void task() {
    for (int i = 0; i < 10000; i++) {
        counts++;
    }    
}

int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout << counts << endl; // prints 14933

    return 0;
}