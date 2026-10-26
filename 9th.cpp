#include <iostream>
using namespace std;
#define MAX 100
int heap[MAX];
int n = 0;
void insert(int value){
    if (n == MAX){
        cout << "OVERFLOW\n";
        return;
    }
    int i = n;
    heap[i] = value;
    n++;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]){
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteMax(){
    if (n == 0){
        cout << "UNDERFLOW\n";
        return;
    }
    cout << "Deleted element: " << heap[0] << endl;
    heap[0] = heap[n - 1];
    n--;
    int i = 0;
    while (2 * i + 1 < n){
        int largest = 2 * i + 1;
        int right = 2 * i + 2;
        if (right < n && heap[right] > heap[largest])
            largest = right;
        if (heap[i] >= heap[largest])
            break;
        swap(heap[i], heap[largest]);
        i = largest;
    }
}
void display(){
    if (n == 0){
        cout << "Priority Queue is empty\n";
        return;
    }
    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;
}
int main(){
    int choice, value;
    do{
        cout << "\n1. Insert";
        cout << "\n2. Delete Maximum";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                deleteMax();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}
