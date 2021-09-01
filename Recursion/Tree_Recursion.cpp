#include<iostream>
using namespace std;


// Find the time and space complexity of this question

// Tree Recursion
void fun(int n){
    if(n > 0){
        cout<<n<<" ";
        fun(n-1);
        fun(n-1);
    }
} 

int main(){
    fun(3 );
    return 0;
}

// Ans : Time complexity - O(2^n); Space Complexity - O(n)