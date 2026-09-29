//Evaluate a postfix algebraic expression with the help of stack. But I have not accounted for the spaces and only considered single digit number.
//to-do check for alphabets 
#include <iostream>
#include <cmath>
using namespace std;
int *stack;
int top=-1;
bool error=false;
void push(int size ,int value){
    if(top==size-1){
        cout<<"Stack Overflow"<<endl;
        error=true;
        return;
    }
    top++;
    stack[top]=value;
}
int pop(){
    if (top==-1){
        cout<<"Stack Underflow"<<endl;
        error=true;
        return 0;
    }
    int value= stack[top];
    top--;
    return value;
}
int main(){
    string postfix;
    cout<<"Enter postfix expression:";
    cin>>postfix;
    int size=postfix.length();
    stack=new int [size];
    for(int i=0;postfix[i]!='\0';i++){
        char ch= postfix[i];
        if (ch>='0' && ch<='9'){
            push(size , ch-'0');
            if(error){
                cout<<"Enter valid postfix expression.";
                return 0;
            }
        }
        /*else if ((ch>='A' && ch<='Z')|| (ch>='a'&& ch<='z')){
            push(size , int(ch));
            if(error){
                cout<<"Enter valid postfix expression.";
                return 0;
            }
        }*/
        else{
            int a=pop();
            if(error){
                return 0;
            }
            int b=pop();
            if(error){
                cout<<"Enter valid postfix expression.";
                return 0;
            }
            int result;
            switch(ch){
               case '+':
               result=b+a;
               break;
               case '-':
               result=b-a;
               break;
               case '*':
               result=b*a;
               break;
               case '/':
               if(a==0){
                cout<<"Division by zero is undefined";
                return 0;
               }
               else{
               result=b/a;
               }
               break;
               case '%':
               result=b%a;
               break;
               case '^':
               result=pow(b,a);
               break;
               default:
               cout<<"Enter valid postfix expression";
               return 0;
            }
            push(size,result);
        }
    }
    if (top!=0){
        cout<<"Enter valid postfix expression"<<endl;
        return 0;
    }
    cout<<"Result:"<<pop();
    return 0;
}
