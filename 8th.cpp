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
Node* insert(Node* root, int value){
    if (root == NULL)
        return new Node(value);
    if (value < root->info)
        root->left = insert(root->left, value);
    else if (value > root->info)
        root->right = insert(root->right, value);
    return root;
}
Node* findMin(Node* root){
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int value){
    if (root == NULL)
        return root;
    if (value < root->info)
        root->left = deleteNode(root->left, value);
    else if (value > root->info)
        root->right = deleteNode(root->right, value);
    else{
        // Node with no child or one child
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }// Node with two children
        Node* temp = findMin(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}
void inorder(Node* root){
    if (root != NULL){
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}
int main()
{
    Node* root = NULL;
    int n, value, choice;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++){
        cin >> value;
        root = insert(root, value);
    }
    cout << "BST in inorder: ";
    inorder(root);
    cout << "\n1. Insert a node";
    cout << "\n2. Delete a node";
    cout << "\nEnter choice: ";
    cin >> choice;
    if (choice == 1){
        cout << "Enter value to insert: ";
        cin >> value;
        root = insert(root, value);
    }
    else if (choice == 2){
        cout << "Enter value to delete: ";
        cin >> value;
        root= deleteNode(root, value);
    }
    else{
        cout << "Invalid choice";
        return 0;
    }
    cout << "BST after operation: ";
    inorder(root);
    return 0;
}
