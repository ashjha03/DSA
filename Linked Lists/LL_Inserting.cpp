#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
} *first, *last;

void Create(int A[], int n){
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i = 1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

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

// If we have to always insert at last -> Maintain last Pointer to use this function
void Insert_Last(int data){
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    if(!first)
         first = last = t;
    else{
        last->next = t;
        last = t;
    }
}

// Insertion in a SORTED linked list
void Insert_Sorted(int data){
    Node *t = new Node;
    t->data = data;
    if(data < first->data){
        t->next = first;
        first = t;
        return;
    }
    Node *p = new Node, *prev = new Node;
    p = first;
    while(p && p->data < data){
        prev = p;
        p = p->next;
    }
    t->next = prev->next;
    prev->next = t;
}

int main(){
    // Creating a Linked List by Insertion
    Insert(1, 0);
    Insert(2, 1);
    Insert(3, 2); 
    Insert(5, 3);
    Insert_Sorted(-2);
    Insert_Sorted(4);
    Insert_Sorted(-4);
    display(first);
    return 0;
}