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
    cout<<endl;
}

void Reverse(Array *arr){
    int *B = new int[arr->length];
    for(int i=0, j=arr->length - 1; i<arr->length; i++, j--)
        B[i] = arr->A[j];
    for(int i=0; i<arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse_2(Array *arr){
    for(int i=0, j=arr->length-1; i < j ; i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main(){
    Array arr = {{1,2,3,4,5}, 10, 5};

    display(&arr);
    Reverse_2(&arr);
    display(&arr);
    return 0;
}