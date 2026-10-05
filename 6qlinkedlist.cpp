#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rear == nullptr) { 
            front = rear = newNode;
            cout << "Inserted: " << item << "\n";
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << "Inserted: " << item << "\n";
    }
    void dequeue() {
        if (front == nullptr) { 
            cout << "Underflow! Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Deleted: " << temp->data << "\n";
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedListQueue lq;
    lq.enqueue(10);
    lq.enqueue(20);
    lq.enqueue(30);
    lq.display();
    lq.dequeue();
    lq.display();
    lq.enqueue(40);
    lq.display();
    lq.dequeue(); 
    lq.dequeue(); 
    lq.dequeue(); 
    lq.display();
    lq.dequeue(); 
    return 0;
}