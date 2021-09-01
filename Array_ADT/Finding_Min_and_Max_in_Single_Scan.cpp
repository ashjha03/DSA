#include<iostream>
using namespace std;

struct Array{
    int A[20];
    int size;
    int length;
};

void display(Array *arr){
    for(int i=0; i<arr->length; i++)
        cout<<arr->A[i]<<" ";
}

void Min_Max(Array arr){
    int min=arr.A[0], max=arr.A[0];
    for(int i=1; i<arr.length; i++)
        if(arr.A[i] < min)
            min = arr.A[i];
        else if(arr.A[i] > max)
            max = arr.A[i];
    
    cout<<"Min and Max are : "<<min<<" , "<<max<<endl;
}

int main(){
    Array arr = {{1,3,5,7,9}, 10, 5};
    Min_Max(arr);
    return 0;
}