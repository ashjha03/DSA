#include<iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
} *first=NULL;

void create(int A[], int n){
    Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Length(Node *p){
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node *p, int data, int pos){
    if(pos<0 || pos > Length(p))
        return;
    Node *t = new Node;
    t->data = data;
    if(pos == 1){
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        for(int i=1; i<pos; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(Node *p, int pos){
    if(pos < 1 || pos > Length(p))
        return -1;
    int data;
    if(pos == 1){
        data = p->data;
        first = first->next;
        if(first)
            first->prev = NULL;
        delete p;
    }
    else{
        for(int i=1; i<pos; i++)
            p = p->next;
        data = p->data;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        delete p;
    }
    return data;
}

void Reverse(Node *p){
    Node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;
        if(p && p->next == NULL)
            first = p;
    }
}

int main(){
    int A[] = {1,2,4,5,6};
    create(A, 5);

    Insert(first,3,2);
    Insert(first,7,6);
    cout<<"Length: "<<Length(first)<<endl;
    Display(first);
    
    cout<<"Deleted: "<<Delete(first,5)<<endl;
    cout<<"Length: "<<Length(first)<<endl;
    Display(first);
    
    Reverse(first);
    cout<<"Reversed"<<endl;
    Display(first);
    return 0;
}