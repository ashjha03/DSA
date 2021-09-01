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

void Remove_Duplicate(){
    Node *p = first->next, *prev = first;
    while(p){
        if(p->data != prev->data){
            prev = p;
            p = p->next;
        }
        else{
            prev->next = p->next;
            delete p;
            p = prev->next;
        }
    }
}

int main(){
    Insert(1, 0);
    Insert(2, 1);
    Insert(2, 2);
    Insert(2, 3);
    Insert(5, 4);
    Insert(6, 5);
    display(first);
    Remove_Duplicate();
    display(first);
    return 0;
}