#include "concurrentqueue.h"

template <typename T>
ConcurrentQueue<T>::ConcurrentQueue()
{
}

template <typename T>
void ConcurrentQueue<T>::push(const T& item)
{
    //std::unique_lock<std::mutex> mlock(mutex);
    queue.push(item);
    //mlock.unlock();
    //cond.notify_one();
}

template <typename T>
void ConcurrentQueue<T>::pop(T& item)
{
    //std::unique_lock<std::mutex> mlock(mutex);
    while(queue.empty())
    {
        //cond.wait(mlock);
    };
    item = queue.front();
    queue.pop();
}

template <typename T>
T ConcurrentQueue<T>::pop()
{
    //std::unique_lock<std::mutex> mlock(mutex);
    while(queue.empty()) {
        //cond.wait(mlock);
    };
    auto item = queue.front();
    queue.pop();
    return item;
}

template <typename T>
T ConcurrentQueue<T>::back()
{
    //std::unique_lock<std::mutex> mlock(mutex);
    while(queue.empty()) {
        //cond.wait(mlock);
    }
    auto item = queue.back();

    return item;
}


template <typename T>
int ConcurrentQueue<T>::size()
{
    return queue.size();
}
