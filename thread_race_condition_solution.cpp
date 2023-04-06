// Critical section problem or Race condition solution

#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

std::mutex mtx;

int counts = 0;

void task() {
    for (int i = 0; i < 10000; i++) {
        mtx.lock();
        counts++;
        mtx.unlock();
    }    
}

int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout << counts << endl; // prints 20000

    return 0;
}