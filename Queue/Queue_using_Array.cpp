#include<iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(int size){
            this->size = size;
            front = rear = -1;
            Q = new int[size];
        }
        void EnQueue(int);
        int DeQueue();
        void Display();
};

void Queue::Display(){
    for(int i = front + 1; i<=rear; i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}

void Queue::EnQueue(int data){
    if(rear == size - 1)
        cout<<"Queue Overflow"<<endl;
    else
        Q[++rear] = data;
}

int Queue::DeQueue(){
    int x = -1;
    if(front == rear) // Empty condition
        cout<<"Queue Underflow"<<endl;
    else
        x = Q[++front];
    return x;
}

int main(){
    Queue q(5);
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    q.Display();
    cout<<"Deleted: "<<q.DeQueue()<<endl;
    q.Display();
    return 0;
}