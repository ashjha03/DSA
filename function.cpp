#include<iostream>
using namespace std;

void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
    y = temp;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_R(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 20;
    cout<<"Original value of a and b are : "<<a<<" "<<b<<endl;
    // swap(a, b); // Call by value
    // swap(&a, &b); // Call by Address
    swap_R(a, b); // Call by Reference
    cout<<"Values of a and b after swappping are : "<<a<<" "<<b<<endl;

    return 0;
}