#include<iostream>
using namespace std;

// arr[]  can also be written as *arr, it will general for any pointer whilw '[]' signifies array to pointer only
void fun(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    
    // ***** sizeof on array function parameter will return size of 'int *' instead of 'int []' *****
    cout<<endl<<sizeof(arr)<<endl;
}

// ****** Returning an Array ******
int * func(int n){
    int *p;
    p = new int[n];

    for(int i = 0; i < n; i++)
        p[i] = i+1;
    return p;
}
int main(){
    int A[] = {1,2,3,4,5};
    fun(A, 5); // Array is always passed by Address, Array can never be passed as value (Call by Value)
    cout<<sizeof(A)<<endl;
    
    int *arr;
    arr = func(10);
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<sizeof(arr)<<endl; 
    return 0;
}