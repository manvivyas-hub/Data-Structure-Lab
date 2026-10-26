#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *left, *right;
    Node(int value){
        info = value;
        left = right = NULL;
    }
};
Node* insert(Node* start, int value){
    if (start == NULL)
        return new Node(value);
    if (value < start->info)
        start->left = insert(start->left, value);
    else if (value > start->info)
        start->right = insert(start->right, value);
    return start;
}
Node* findMin(Node* start){
    while (start != NULL && start->left != NULL)
        start = start->left;
    return start;
}
Node* deleteNode(Node* start, int value){
    if (start == NULL)
        return start;
    if (value < start->info)
        start->left = deleteNode(start->left, value);
    else if (value > start->info)
        start->right = deleteNode(start->right, value);
    else{
        // Node with no child or one child
        if (start->left == NULL){
            Node* temp = start->right;
            delete start;
            return temp;
        }
        else if (start->right == NULL){
            Node* temp = start->left;
            delete start;
            return temp;
        }// Node with two children
        Node* temp = findMin(start->right);
        start->info = temp->info;
        start->right = deleteNode(start->right, temp->info);
    }
    return start;
}
void inorder(Node* start){
    if (start != NULL){
        inorder(start->left);
        cout << start->info << " ";
        inorder(start->right);
    }
}
int main()
{
    Node* start = NULL;
    int n, value, choice;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++){
        cin >> value;
        start = insert(start, value);
    }
    cout << "BST in inorder: ";
    inorder(start);
    cout << "\n1. Insert a node";
    cout << "\n2. Delete a node";
    cout << "\nEnter choice: ";
    cin >> choice;
    if (choice == 1){
        cout << "Enter value to insert: ";
        cin >> value;
        start = insert(start, value);
    }
    else if (choice == 2){
        cout << "Enter value to delete: ";
        cin >> value;
        start = deleteNode(start, value);
    }
    else{
        cout << "Invalid choice";
        return 0;
    }
    cout << "BST after operation: ";
    inorder(start);
    return 0;
}
