#include<iostream>
using namespace std;

void fun1(int n){
    if(n > 0){
        cout<<n<<" ";
        fun1(n-1);
    }
}

void fun2(int n){
    if(n > 0){
        fun2(n-1);
        cout<<n<<" ";
    }
}

int main(){
    fun1(5);
    cout<<endl;
    fun2(5);
    return 0;
}