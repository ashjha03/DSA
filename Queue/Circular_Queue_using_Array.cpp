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
            front = rear = 0; // Here, front and rear should be at 0
            Q = new int[size];
        }
        void EnQueue(int);
        int DeQueue();
        void Display();
};

void Queue::Display(){
    int i = front+1;
    do{
        cout<<Q[i]<<" ";
        i = (i + 1) % size;
    }while(i != (rear+1)%size);
    cout<<endl;
}

void Queue::EnQueue(int data){
    if((rear + 1) % size == front)
        cout<<"Queue Overflow"<<endl;
    else{
        rear = (rear + 1) % size;
        Q[rear] = data;
    }
}

int Queue::DeQueue(){
    int x = -1;
    if(front == rear) // Empty condition
        cout<<"Queue Underflow"<<endl;
    else{
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

int main(){
    Queue q(6);
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    q.EnQueue(5);
    q.Display();
    cout<<"Deleted: "<<q.DeQueue()<<endl;
    q.Display();
    q.EnQueue(6);
    q.Display();
    return 0;
}