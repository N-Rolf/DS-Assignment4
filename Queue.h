#ifndef _QUEUE_H
#include <string>

typedef string QElement;

class Queue
{
    public:
        Queue(...);
        Queue(Queue &);
        ~Queue();
        void enqueue(const Element);
        QElement dequeue();
        void view();
        bool isEmpty() const;
        bool isFull() const;
    private:
        const short Q_SIZE;
        typedef QElement * QPointer;
        QPointer Queue;
        short head, tail;
};

#endif