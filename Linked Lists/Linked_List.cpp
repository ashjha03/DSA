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

// **************** Display using Recursion ****************
void Display(Node *p){
    if(p){
        cout<<p->data<<endl;
        Display(p->next);
    }
}

int main(){
    int A[] = {1, 2, 3, 4, 5}; 
    Create(A, 5); 
    Display(first);
    return 0;
}