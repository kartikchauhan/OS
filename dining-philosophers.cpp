//https://leetcode.com/problems/the-dining-philosophers/description/

#include <mutex>

using namespace std;

class Semaphore {
    public:
        Semaphore() {}

        Semaphore(int c) : count(c) {}

        void setCount(int a) {
            count = a;
        }

        inline void signal() {
            unique_lock<mutex> lock(mtx);
            count++;

            if (count <= 0) {
                cv.notify_all();
            }
        }

        inline void wait() {
            unique_lock<mutex> lock(mtx);
            count--;

            while (count < 0) {
                cv.wait(lock);
            }
        }
    
    private:
        mutex mtx;
        condition_variable cv;
        int count;
};

class DiningPhilosophers {
    
public:
    Semaphore fork[5];
    mutex m;
    condition_variable cv;

    DiningPhilosophers() {
        for (int i=0; i<5; i++) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {

        lock_guard<mutex> lock(m);
        fork[(philosopher + 1) % 5].wait();
        fork[philosopher].wait();

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[(philosopher + 1) % 5].signal();

        putRightFork();
        fork[philosopher].signal();
    }
};