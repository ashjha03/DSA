#include<iostream>
using namespace std;

int main(){
    int a = 10;
    // ****** Reference is nothing but another name to the same variable ******
    int &r = a; // Reference Variable must be Initialized at the time of Declaration, Otherwise it will throw ERROR!!
    r++; 
    cout<<a<<" \nUsing Reference : "<<r<<endl;
    int b = 20;
    r = b; // This does not mean that r is referencing to B now, This is Assigment not Initialization 
    cout<<a<<" \nUsing Reference : "<<r<<endl;
    return 0;
}