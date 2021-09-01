 #include<iostream>
 #include <cmath>
#include <stack>
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

// Method 1 --> Find length of linked list and make loop of half of length

// Method 2
int middle(Node *p){
    Node *q = first;
    while(q){
        q = q->next;
        if(q)
            q = q->next;
        if(q)
            p = p->next;
    }
    return p->data;
}

// Method 3 --> Using Stacks
void middleNode3(Node* p){
    stack<Node*> s;
    while (p){
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int popLength = (int)(floor(length/2.0));
    while (popLength){
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl;
}
 

int main(){
    int A[] = {1, 3, 5, 7, 9}; 
    Create(A, 5);
    middleNode3(first);
    return 0;
}