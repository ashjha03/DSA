 #include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
} *first=NULL;

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

int CheckLoop(Node *t){
    if(first->next==NULL)
            return false;
    Node *p, *q;
    p = q = t;
    do{
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL;
    }while(p && q && p!=q);

    return p==q ? 1 : 0;
}

int main(){
    int A[] = {1, 3, 5, 7, 9}; 
    Create(A, 5);
    Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    cout<<CheckLoop(first)<<endl;
    return 0;
}