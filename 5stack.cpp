#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int main(){
    string postfix;
    stack<int> s;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    for (int i = 0; i < postfix.length(); i++){
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9'){
            s.push(ch - '0');
        }
        else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            int result;
            switch (ch){
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            case '^':
                result = pow(b, a);
                break;
            }
            s.push(result);
        }
    }
    cout << "Result = " << s.top() << endl;
    return 0;
}