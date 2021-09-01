#include<iostream>
using namespace std;

double e(int x, int n){
    static double p = 1, f = 1;
    double r;
    if(!n)
        return 1;
    else{
        r = e(x, n-1);
        p *= x;
        f *= n;
        return r + p/f;
    }
}

double taylor(double x, double n){
    double s = 1;
    for(; n > 0; n--)
        s = 1 + x/n * s;
    return s;
}

// Horner's Rule
double taylor_recursion(double x, double n){
    double static s = 1;
    if(!n)
        return s;
    else{
        s = 1 + ( x/n * s);
        return taylor_recursion(x, n-1);
        }
}

int main(){
    cout<<taylor_recursion(1,10);
    return 0;
}