#include "concurrentqueue.h"

template <typename T>
ConcurrentQueue<T>::ConcurrentQueue()
{
}

template <typename T>
void ConcurrentQueue<T>::push(const T& item)
{

    queue.push(item);

}

template <typename T>
void ConcurrentQueue<T>::pop(T& item)
{

    while(queue.empty())
    {

    };
    item = queue.front();
    queue.pop();
}

template <typename T>
T ConcurrentQueue<T>::pop()
{

    while(queue.empty()) {

    };
    auto item = queue.front();
    queue.pop();
    return item;
}

template <typename T>
T ConcurrentQueue<T>::back()
{

    while(queue.empty()) {

    }
    auto item = queue.back();

    return item;
}


template <typename T>
int ConcurrentQueue<T>::size()
{
    return queue.size();
}
