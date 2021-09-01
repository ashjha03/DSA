#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int area(struct Rectangle rec){
    return rec.length * rec.breadth;
}

int area_R(struct Rectangle &rec){
    return rec.length * rec.breadth;
}

int length(struct Rectangle *rec, int l){
    rec->length = l; 
    return rec->length;
}

//***** Creating Structure taking memory in HEAP *****
struct Rectangle * fun(){
    Rectangle *p = new Rectangle;
    p->length = 11;
    p->breadth = 23;
    return p;
}

int main(){
    Rectangle R = {10, 20};
    cout<<"Area of Rectangle is : "<<area(R)<<endl; // Call by Value
    // ***** If Structure contain array as a member and is passed by value, Then Array will also passed by value ***** 
    cout<<"Area of Rectangle is : "<<area_R(R)<<endl; // Call by Address
    cout<<"Updated length of Rectangle is : "<<length(&R, 30)<<endl; // Call by Reference

    Rectangle * x = fun();
    cout<<"Length : "<<x->length<<endl<<"Breadth : "<<x->breadth<<endl;
    return 0;
}