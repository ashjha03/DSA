#include<iostream>
#include<string.h>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        char *A;
    public:
        Stack(int s){
            size = s;
            A = new char[size];
            top = -1;
        }
        int isEmpty(){
            if(top == -1)
                return 1;
            return 0;
        }
        char stackTop();
        void push(char);
        char pop();
};

char Stack::stackTop(){
    if(top == -1)
        return '\0';
    else
        return A[top];
}

void Stack::push(char data){
    if(top == size - 1)
        cout<<"Overflow"<<endl;
    else
        A[++top] = data;
}

char Stack::pop(){
    char x = '\0';
    if(top == -1)
        cout<<"Underflow"<<endl;
    else{
        x = A[top];
        top--;
    }
    return x;
}

int isOperand(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    else
        return 1;
}

int pre(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else
        return 0;
}

// Very simple Conversion
char *InfixToPostfix(string infix){
    int n = infix.size();
    Stack p(n);
    char *arr = new char[n];
    string postfix;
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            arr[j++] = infix[i++];
        else{
            if(pre(infix[i]) > pre(p.stackTop()))
                p.push(infix[i++]);
            else
                arr[j++] = p.pop();
        }
    }
    while(!p.isEmpty())
        arr[j++] = p.pop();
    return arr;
}

int main(){
    string s ="a+b*c-d";
    cout<<InfixToPostfix(s)<<endl;
    return 0;
}