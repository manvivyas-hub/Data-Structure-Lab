#include <iostream>
#include <cmath>
using namespace std;
int stack[100];
int top= -1;
void push(int value){
    top++;
    stack[top]=value;
}
int pop(){
    int value= stack[top];
    top--;
    return value;
}
int main(){
    char postfix[100];
    cout<<"Enter postfix expression:";
    cin>>postfix;
    for(int i=0;postfix[i]!='\0';i++){
        char ch= postfix[i];
        if (ch>='0' && ch<='9'){
            push(ch-'0');
        }
        else{
            int a=pop();
            int b=pop();
            int result;
            switch(ch){
                case'+':
                result=b+a;
                break;
                case'-':
                result=b-a;
                break;
                case'*':
                result=b*a;
                break;
                case'/':
                result=b/a;
                break;
                case'%':
                result=b%a;
                break;
                case'^':
                result=pow(b,a);
                break;
            }
            push(result);
        }
    }
    cout<<"Result:"<<pop();
    return 0;
}
