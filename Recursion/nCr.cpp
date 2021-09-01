#include<iostream>
using namespace std;

// Use this method or write a function for factorial and return nCr via formula
int nCr(int n, int r){
    if( (!r) || n == r)
        return 1;
    return nCr(n-1, r) + nCr(n-1, r-1);
}

int main(){
    cout<<nCr(4,2);
    return 0;
}