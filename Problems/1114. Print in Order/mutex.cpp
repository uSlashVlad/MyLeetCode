#include "../includes.hpp"
using namespace std;

class Foo
{
public:
    Foo()
    {
        secondMutex.lock();
        thirdMutex.lock();
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        secondMutex.unlock();
    }

    void second(function<void()> printSecond)
    {
        lock_guard<mutex> lock(secondMutex);

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        thirdMutex.unlock();
    }

    void third(function<void()> printThird)
    {
        lock_guard<mutex> lock(thirdMutex);

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

    mutex secondMutex;
    mutex thirdMutex;
};
