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

int Count(Node *p){
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

// Recursively
int count(Node *p){
    if(!p)
        return 0;
    else
        return count(p->next) + 1;
}

int add(Node *p){
    int sum = 0;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// Recursively
int Sum(Node *p){
    if(!p)
        return 0;
    else 
         return Sum(p->next) + p->data;
}

int max(Node *p){
    int m = -32768; // MIN_INT
    while (p)
    {
        if(p->data > m)
            m = p->data;
        p = p->next;
    }
    return m; 
}

// Recursively
int Max(Node *p){
    int x = 0;
    if(!p)
        return  -32768; // MIN_INT
    x = max(p->next);
    return x > p->data ? x : p->data;
}

int main(){
    int A[] = {1, 2, 3, 4, 5}; 
    Create(A, 5); 
    cout<<"Length: "<<Count(first)<<endl;
    cout<<"Sum: "<<Sum(first)<<endl;
    cout<<"Maximum: "<<Max(first)<<endl;
    return 0;
}