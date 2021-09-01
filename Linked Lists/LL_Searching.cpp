#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
} *first;

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

Node *Search(Node *p, int key){
    while(p){
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Linear Search with modification -> MOVE TO HEAD
Node *Search_(Node *p, int key){
    Node *prev = NULL;
    while(p){
        if(key == p->data){
            prev->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        prev = p;
        p = p->next;
    }
    return NULL;
}

// Recursively
Node *search(Node *p, int key){
    if(!p)
        return NULL;
    if(key == p->data)
        return p;
    return search(p->next, key);
}

int main(){
    int A[] = {1, 2, 3, 4, 5}; 
    Create(A, 5);
    Node *q = Search(first, 4);
    cout<<q->data<<endl;
    return 0;
}