#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node*createTree(){
    int value;
    cout<<"Enter data (-1 for no value):";
    cin>>value;
    if(value==-1){
        return NULL;
    }
    Node *newNode= new Node;
    newNode->data=value;
    cout<<"Enter left child of "<<value<<endl;
    newNode->left=createTree();
    cout<<"Enter right child of "<<value<<endl;
    newNode->right=createTree();
    return newNode;
}
void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    cout<<"Create a binary tree:"<<endl;
    Node *root=createTree();
    cout<<"\nPreorder Traversal:";
    preorder(root);
    cout<<"\nInorder Traversal:";
    inorder(root);
    cout<<"\nPostorder Traversal:";
    postorder(root);
    return 0;
}
