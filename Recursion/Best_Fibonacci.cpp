#include<iostream>
using namespace std;

int A[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int fib(int n){
    if(n <= 1){
        A[n] = n;
        return n;
    }
    else{
        if(A[n-2] == -1)
            A[n-2] = fib(n-2);
        if(A[n-1] == -1)
            A[n-1] = fib(n-1);
        return A[n-1] + A[n-2];
    }
}

int main(){
    cout<<fib(7);
    return 0;
}