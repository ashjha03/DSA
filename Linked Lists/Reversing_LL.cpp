/* 
    There are two methods:
        1. By Reversing Data
        2. By Reversing Links --> USED ALWAYS
*/

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

// Method 1
void Reverse(){
     int arr[5], i=0;
    Node *p = first;
    while(p){
        arr[i++] = p->data; 
        p = p->next;
    }
    p = first;
    while(p){
        p->data = arr[--i];
        p = p->next; 
    }
}

// Method 2
void Reverse_(){
    Node *p = first, *q = NULL, *r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Recursively
void Recur_Reverse(Node *q, Node *p){
    if(p){
        Recur_Reverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

int main(){
    int A[] = {1, 2, 3, 4, 5}; 
    Create(A, 5);
    display(first);
    Reverse(); 
    display(first);
    Reverse_();
    display(first);
    Recur_Reverse(NULL, first);
    display(first);
    return 0;
}