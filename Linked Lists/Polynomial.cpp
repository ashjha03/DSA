#include<iostream>
#include <math.h>
using namespace std;

struct Node{
    int coeff;
    int exp;
    Node *next;
}*poly = NULL;

void Create(){
    Node *t, *last = NULL;
    int num, i;
    cout<<"Enter Number of Terms : ";
    cin>>num;
    cout<<"Enter each term with coeff and exp\n";

    for(i=0; i<num; i++){
        t = new Node;
        cin>>t->coeff>>t->exp;
        t->next = NULL;
        if(poly == NULL)
            poly = last = t;
        else{
            last->next = t;
            last = t;
        }
    }
}

void Display(Node *p){
    while(p){
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p = p->next;
    }
    cout<<endl;
}

long Eval(struct Node *p, int x){
    long val = 0;
    while(p){
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
   return val;
}

int main(){
    Create();
    Display(poly);
    cout<<Eval(poly, 1)<<endl;

    return 0;
}