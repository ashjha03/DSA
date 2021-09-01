#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class DEQUEUE{
    private:
        Node *front, *rear;
    public:
        void Display();
        void Insert_front(int);
        void Insert_rear(int);
        int Delete_front();
        int Delete_rear();
};

void DEQUEUE::Display(){
    if(front == NULL)
        cout<<"DEQUEUE Underflow"<<endl;
    else{
        Node *p = front;
        while(p != rear){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<rear->data<<endl;
    }
}

void DEQUEUE::Insert_front(int data){
    Node *t = new Node;
    if(t == NULL)
        cout<<"DEQUEUE Overflow"<<endl;
    else{
        t->data = data;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            t->next = front;
            front = t;
        }
    }
}

void DEQUEUE::Insert_rear(int data){
    Node *t = new Node;
    if(t == NULL)
        cout<<"DEQUEUE Overflow"<<endl;
    else{
        t->data = data;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int DEQUEUE::Delete_front(){
    int x = -1;
    if(front == NULL)
        cout<<"DEQUEUE Underflow"<<endl;
    else{
        Node *p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

int DEQUEUE::Delete_rear(){
    int x = -1;
    if(front == NULL)
        cout<<"DEQUEUE Underflow"<<endl;
    else{
        Node *p = front, *q = rear;
        while(p->next != rear)
            p = p->next;
        x = q->data;
        p->next = NULL;
        delete q;
    }
    return x;
}

int main(){
    DEQUEUE dq;
    dq.Display();
    dq.Insert_front(0);
    dq.Insert_rear(1);
    dq.Insert_rear(2);
    dq.Insert_rear(3);
    dq.Insert_rear(4);
    dq.Insert_rear(5);
    dq.Display();
    cout<<dq.Delete_rear()<<endl;
    dq.Display();
    cout<<dq.Delete_front()<<endl;
    dq.Display();
    return 0;
}