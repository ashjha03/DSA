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

void Delete(int pos){
    Node *p, *prev;
    p = first;
    if(pos == 1){
        first = first->next;
        delete p;
        return;
    }

    for(int i=1; i<pos && p; i++){
        prev = p;
        p = p->next;
    }
    prev->next = p->next;
    delete p;
}

void Delete_First(){
    Node *t = first;
    first = first->next;
    int x = t->data;
    delete t;
}

int main(){
    Insert(1, 0);
    Insert(2, 1);
    Insert(3, 2); 
    Insert(4, 3);
    Insert(5, 4);
    Insert(6, 5);
    Delete_First();
    Delete(2);
    display(first);
    return 0;
}