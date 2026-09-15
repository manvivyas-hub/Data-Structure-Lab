#include <iostream>
using namespace std;
struct Node
{   int info;
    Node* link;
};
void insertBeginning(Node*& start, Node*& avail, int value)
{    
    if (avail==NULL){
        cout<<"OVERFLOW";
        return ;
    }
    Node* newNode = avail;
    avail = avail->link;
    newNode->info = value;
    newNode->link = start;
    start = newNode;
}
void insertPosition(Node*& start, Node*& avail, int value, int position)
{   if (avail==NULL){
        cout<<"OVERFLOW";
        return;
    }
    Node* newNode = avail;
    avail = avail->link;
    newNode->info = value;
    if (position<1){
        cout<<"Invalid Position"<<endl;
    }
    if (position == 1)
    {  newNode->link = start;
        start = newNode;
        return;
    }
    Node* temp = start;
    for (int i = 1; i < position - 1; i++){
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}
void insertEnd(Node*& start, Node*& avail, int value)
{   if (avail==NULL){
        cout<<"OVERFLOW";
        return;
    }
    Node* newNode = avail;
    avail = avail->link;
    newNode->info = value;
    newNode->link = NULL;
    if (start == NULL)
    {   start = newNode;
        return;
    }
    Node* temp = start;
    while (temp->link != NULL){
    temp = temp->link;
    }
    temp->link = newNode;
}
void deleteBeginning(Node*& start, Node*& avail)
{
    if (start == NULL)
    {   cout << "UNDERFLOW" << endl;
        return;
    }
    Node* temp = start;
    start = start->link;
    temp->link = avail;// attaching the node to the front of the avail 
    avail = temp;
}
void deletePosition(Node*& start, Node*& avail, int position)
{
    if (start == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }
    if (position <1){
        cout<<"Invalid Position"<<endl;
    }
    if (position == 1)
    {
        Node* temp = start;
        start = start->link;
        temp->link = avail;
        avail = temp;
        return;
    }
    Node* temp = start;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->link;
    }
    Node* deletedNode = temp->link;
    temp->link = deletedNode->link;
    deletedNode->link = avail;
    avail = deletedNode;
}
void deleteEnd(Node*& start, Node*& avail)
{
    if (start == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }
    if (start->link == NULL)
    {
        Node* temp = start;
        start = NULL;
        temp->link = avail;
        avail = temp;
        return;
    }
    Node* temp = start;
    while (temp->link->link != NULL)//stops at 2nd last node 
    {
        temp = temp->link;
    }

    Node* deletedNode = temp->link;//copy the last node to deleted node
    temp->link = NULL;
    deletedNode->link = avail;
    avail = deletedNode;
}


void display(Node* start)
{   Node* temp = start;
    while (temp != NULL)
    {
        cout << temp->info << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int main()
{
Node*start=NULL;
Node*node1=new Node;
Node*node2=new Node;
Node*node3=new Node;
Node*node4=new Node;
Node*node5=new Node;
Node*node6=new Node;
node1->link=node2;
node2->link=node3;
node3->link=node4;
node4->link=node5;
node5->link=node6;
node6->link=NULL;
Node*avail=node1;
int value;
int position;
int x;
int y;
int z;
int size;
cout<<"Enter the number of elements of the linked list:";
cin>>size;
if (size < 0 || size > 6){
     cout << "Invalid size. Maximum 6 elements can be inserted." << endl;
     return 0;
}
cout<<"Enter the elements of the linked list:"<<endl;
for(int i=0;i<size; i++){
    cin>>value;
    insertEnd(start,avail,value);
}
do{
cout<<"Select"<<" "<< "1: INSERTION "<<" "<<"2: DELETION "<<"3: NO CHANGE"<<endl;
cin>>x;
switch (x)
{
case 1:
    cout<<"Select"<<" "<< "1: insertion at beginning "<<" "<<"2: insertion at a location"<<" "<< "3: insertion at end "<<endl;
    cin>>y;
    switch(y){
    case 1:
    cout<<"Enter the element to be inserted at beginning:";
    cin>>value;
    insertBeginning(start,avail,value);
    cout<<"After insertion"<<endl;
    display(start);
    break;
    case 2:
    cout<<"Enter the element to be inserted at a particular position:";
    cin>>value;
    cout<<"Enter the position at which you want to insert:";
    cin>>position;
    insertPosition(start,avail,value,position);
    cout<<"After insertion"<<endl;
    display(start);
    break;
    case 3:
    cout<<"Enter the element to be inserted at end:";
    cin>>value;
    insertEnd(start,avail,value);
    cout<<"After insertion"<<endl;
    display(start);
    break;
    }
    break;
case 2:
    cout<<"Select"<<" "<< "1: Deletion at beginning "<<" "<<"2: Deletion at a location"<<" "<< "3: Deletion at end "<<endl;
    cin>>z;
    switch(z){
    case 1:
    deleteBeginning(start,avail);
    cout<<"After deletion"<<endl;
    display(start);
    break;
    case 2:
    cout<<"Enter the position at which you want to delete the node:";
    cin>>position;
    deletePosition(start,avail,position);
    cout<<"After deletion"<<endl;
    display(start);
    break;
    case 3:
    deleteEnd(start,avail);
    cout<<"After deletion"<<endl;
    display(start);
    break;
    }
    break;
case 3:
   display(start);
}
}
while(x!=3);
return 0;
}
