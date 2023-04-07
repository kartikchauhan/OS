// https://leetcode.com/problems/fizz-buzz-multithreaded/description/

/**
Thread A: calls fizz() that should output the word "fizz".
Thread B: calls buzz() that should output the word "buzz".
Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
Thread D: calls number() that should only output the integers.

"fizzbuzz" if i is divisible by 3 and 5,
"fizz" if i is divisible by 3 and not 5,
"buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.

*/

#include <mutex>
using namespace std;

class FizzBuzz {
    mutex m;
    condition_variable cv;

private:
    int n;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (this->i <= this->n) {
            unique_lock<mutex> lock(m);

            while (this->i <= this-> n && ! (this->i % 3 == 0 && this->i % 5 != 0)) {
                cv.wait(lock);
            }

            if (i <= n) {
                printFizz();
                ++i;
            }

            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (this->i <= this->n) {
            unique_lock<mutex> lock(m);

            while (this->i <= this-> n && ! (this->i % 5 == 0 && this->i % 3 != 0)) {
                cv.wait(lock);
            }

            if (i <= n) {
                printBuzz();
                ++i;
            }

            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (this->i <= this->n) {
            unique_lock<mutex> lock(m);

            while (this->i <= this-> n && ! (this->i % 3 == 0 && this->i % 5 == 0)) {
                cv.wait(lock);
            }

            if (i <= n) {
                printFizzBuzz();
                ++i;
            }

            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (this->i <= this->n) {
            unique_lock<mutex> lock(m);

            while (this->i <= this-> n && ! (this->i % 3 != 0 && this->i % 5 != 0)) {
                cv.wait(lock);
            }

            if (i <= n) {
                printNumber(this->i);
                ++i;
            }

            cv.notify_all();
        }
    }
};