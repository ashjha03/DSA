#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue_LL{
    private:
        Node *front, *rear;
    public:
        void display();
        void Enqueue(int);
        int Dequeue();
};

void Queue_LL::display(){
    if(front == NULL)
        cout<<"Queue Underflow"<<endl;
    else{
        Node *p = front;
        while(p != rear){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<rear->data;
        cout<<endl;
    }
}

void Queue_LL::Enqueue(int data){
    Node *t = new Node;
    if(t == NULL) // isFull condition
        cout<<"Queue Overflow"<<endl;
    else{
        t->data = data;
        t->next = NULL;
        if(front == NULL) // isEmpty condition
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int Queue_LL::Dequeue(){
    int x = -1;
    Node *p;
    if(front == NULL)
        cout<<"Queue Underflow"<<endl;
    else{
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main(){
    Queue_LL q;
    q.display();
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.display();
    q.Enqueue(4);
    q.Enqueue(5);
    q.display();
    cout<<q.Dequeue()<<endl;
    q.display();
    return 0;
}