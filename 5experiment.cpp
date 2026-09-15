//Evaluate a postfix algebraic expression with the help of stack. but in this I have not accounted for the spaces and only considered single digit number
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
void push(int stack[], int &top, int MaxStack, int item){
    if(top==MaxStack-1){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    else {
        top++;
        stack[top]=item;
    }
}

int pop(int stack[], int &top){
    if (top==-1){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    else{
       int item=stack[top];
       top--;
       return item;
    }
}

int main(){
   char ch;
   string postfix;
   int stack[15];
   int top=-1;
   cout<<"Enter postfix expression:";
   getline(cin, postfix);
   int MaxStack=postfix.length();
   for(int i=0; i<MaxStack; i++){
        ch=postfix[i];
        if(isdigit(ch)){
            push(stack,top,15,ch- '0');
        }
        else{
           int A=pop(stack,top);
           int B=pop(stack,top);
           int result;
           switch(ch){
           case ('+'):
           result= B+A;
           break;
           case ('-'):
           result= B-A;
           break;
           case ('*'):
           result= B*A;
           break;
           case ('/'):
           result= B/A;
           break;
           case ('^'):
           result=pow(B,A);
           break;
           }
           push(stack,top,15,result);
        }
   }
   cout<<"Result:"<<pop(stack,top);
   return 0;
}