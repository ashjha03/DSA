#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    // struct Rectangle r = {10, 5}; // In C++ struct keyword is not necessary while it is necessary in C language 
    // struct Rectangle *p = &r;
    // r.length = 15; // This is Correct
    // // p.length = 15; // This is InCorrect because p is a pointer variable
    // // *p.length = 15; // This is InCorrect as '.' has higher precedence than '*'
    // (*p).length = 15; // This is Correct
    // p->breadth = 20; // This method is applicable is C++ only


    // **** Dynamic Allocation -> Memory in HEAP *****
    struct Rectangle *p;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p = new  Rectangle;
    p->length = 10;
    p->breadth = 15;
    cout<<p->length<<" "<<p->breadth<<endl;
    return 0;
}