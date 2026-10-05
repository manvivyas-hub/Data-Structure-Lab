#include <iostream>
using namespace std;
class ArrayQueue {
private:
    int* queue;
    int front;
    int rear;
    int size;
public:
    ArrayQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }
    ~ArrayQueue() {
        delete[] queue;
    }
    void enqueue(int item) {
        if ((front==0 && rear==size-1) || (front==rear+1)) {
            cout << "Overflow! Queue is full.\n";
            return;
        }
        if (front==-1) {
            front = 0;
            rear = 0;
        }
        else if (rear==size-1) {
            rear = 0;
        }
        else {
            rear++;
        }

        queue[rear] = item;
        cout << "Inserted: " << item << "\n";
    }
    void dequeue(){
        if (front==-1) {
            cout << "Underflow! Queue is empty.\n";
            return;
        }
        int item = queue[front];
        cout << "Deleted: " << item << "\n";
        if (front==rear) {
            front = -1;
            rear = -1;
        }
        else if (front==size-1) {
            front = 0;
        }
        else {
            front++;
        }
    }
    void display() {
        if (front==-1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        if (rear>=front) {
            for (int i=front; i<=rear; i++)
                cout << queue[i] << " ";
        } else {
            for (int i=front; i<size; i++)
                cout << queue[i] << " ";
            for (int i=0;i<=rear; i++)
                cout << queue[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    ArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.display();
    return 0;
}