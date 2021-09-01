 #include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
} *first=NULL, *second=NULL,*third=NULL;

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

void Create2(int A[], int n){
    int i;
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    
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

void Concatenation(Node *p, Node *q){
    p = first;
    while(p->next)
        p = p->next;
    p->next = q;
    q = NULL;
}

void Merge(Node *p, Node *q){
    Node *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p)
        last->next = p;
    else
        last->next = q;
}

int main(){
    int A[] = {1, 3, 5, 7, 9}; 
    int B[] = {2, 4, 6, 8, 10}; 
    Create(A, 5);
    Create2(B, 5);
    // Concatenation(first, second);
    Merge(first, second);
    display(third);
    return 0;
}