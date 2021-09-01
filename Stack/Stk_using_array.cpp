#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *A;
    public:
        Stack(int s){
            size = s;
            A = new int[size];
            top = -1;
        }
        // All Operations are taking O(1) Time Complexity
        void display();
        int isEmpty();
        int isFull();
        int stackTop();
        void push(int);
        int pop();
        int peek(int);
};

void Stack::display(){
    for(int i=0; i<=top; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int Stack::isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack::isFull(){
    if(top == size - 1)
        return 1;
    else
        return 0;
}

int Stack::stackTop(){
    if(top == -1)
        return -1;
    else
        return A[top];
}

void Stack::push(int data){
    if(top == size - 1)
        cout<<"Overflow"<<endl;
    else
        A[++top] = data;
}

int Stack::pop(){
    int x = -1;
    if(top == -1)
        cout<<"Underflow"<<endl;
    else{
        x = A[top];
        top--;
    }
    return x;
}

int Stack::peek(int pos){
    if(pos < 1 || pos > size)
        return -1;
    else
        return A[top - pos + 1];
}

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    cout<<st.peek(2)<<endl<<st.stackTop()<<endl;
    return 0;
}