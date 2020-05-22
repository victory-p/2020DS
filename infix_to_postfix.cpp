#include <iostream>
#include <cstring>
#define SIZE 50
#define EOS '$'
using namespace std;

class mystack{
    char s[SIZE];
    int top;
public:
    void init();
    void push(char c);
    char pop();
    bool stack_empty();
    char top_element();
    bool operand(char c);
    int priority(char op);
};

void mystack :: init(){
    top = 0;
}

void mystack :: push(char c){
    s[top] = c;
    top++;
}

char mystack :: pop(){
    top--;
    return s[top];
}

bool mystack :: stack_empty(){
    if(top == 0) return true;
    else return false;
}

char mystack :: top_element(){
    return (s[top-1]);
}

bool operand(char c){
    if((c == '(') || (c == ')') || (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%') || (c == '$')) return false;
    else return true;
}

int priority(char op){
    if((op == '(') || (op == '$')) return 0;
    if((op == '+') || (op == '-')) return 1;
    if((op == '*') || (op == '/') || (op == '%')) return 2;

    return -1;
}

int main(){
    mystack s;
    char input[SIZE];
    char c;
    string infix;
    string postfix;

    s.init();

    cout << "infix 수식 입력 ";
    cin.getline(input, 50);
    infix = input;
    infix += EOS;

    int len = infix.length();

    for(int i=0; i<len; i++){
        if(operand(infix[i])) postfix += infix[i];
        else{
            if(infix[i] == '('){
                s.push(infix[i]);
            }
            else if(infix[i] == ')'){
                while(s.top_element() != '('){
                    c = s.pop();
                    postfix += c;
                }
                c = s.pop();
            }
            else{
                while(1){
                    if(priority(infix[i])>priority(s.top_element())){
                        s.push(infix[i]);
                        break;
                    }
                    c = s.pop();
                    postfix += c;
                }
            }
        }
    }

    cout << postfix << endl;

    return 0;
}
