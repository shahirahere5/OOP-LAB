#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
private:
    T* data;
    int front, rear, count, capacity;

public:
    Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (count == capacity)
            throw QueueOverflowException();

        rear = (rear + 1) % capacity;
        data[rear] = value;
        count++;
    }

    T dequeue() {
        if (count == 0)
            throw QueueUnderflowException();

        T value = data[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }
};

int main() {
    Queue<int> q(3);

    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    } catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException  - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
    } catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException  - what(): " << e.what() << endl;
    }

    return 0;
}