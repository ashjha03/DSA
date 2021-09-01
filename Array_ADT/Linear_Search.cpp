#include<iostream>
using namespace std;

struct Array{
    int A[20];
    int size;
    int length;
};

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Linear_Search(Array *arr, int key){
    for(int i=0; i<arr->length; i++)
        if(key == arr->A[i]){
            
            return i;

            // ******** Techniques, so that finding same element next time becomes easy ********

            // **************** Transposition **************** 
            // swap(&arr->A[i], &arr->A[i-1]);
            // return i-1;

            // **************** Move to Head ****************  
            // swap(&arr->A[i], &arr->A[0]);
            // return 0;
        }
    return -1;
}

void display(Array *arr){
    for(int i=0; i<arr->length; i++)
        cout<<arr->A[i]<<" ";
}

int main(){
    Array arr = { {1,2,3,4,5}, 10, 5};
    cout<<"Element found at index : "<<Linear_Search(&arr, 6);
    return 0;
}