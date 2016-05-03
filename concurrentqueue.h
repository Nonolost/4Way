#ifndef CONCURRENTQUEUE_H
#define CONCURRENTQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class ConcurrentQueue
{
public:
    ConcurrentQueue();
    void push(const T& item);
    void pop(T& item);
    T pop();
    T back();
    int size();

private:
    std::queue<T> queue;
    //std::condition_variable cond;
};

#endif // CONCURRENTQUEUE_H
