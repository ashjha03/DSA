#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
} *first;

void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void Insert(int data, int pos){
    Node *t = new Node, *p;
    t->data = data;
    if(pos == 0){
        t->next = first;
        first = t;
    }
    else{
        p = first;
        for(int i=1; i<pos && p; i++)
            p = p->next;
        t->next = p->next;
        p->next = t; 
    }
}

int isSorted(){
    int x = -32768;
    Node *p = first;
    while(p){
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main(){
    Insert(1, 0);
    Insert(2, 1);
    Insert(3, 2); 
    Insert(4, 3);
    Insert(5, 4);
    Insert(6, 5);
    cout<<isSorted()<<endl;
    // display(first);
    return 0;
}