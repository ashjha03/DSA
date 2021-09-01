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

void display(Array *arr){
    for(int i=0; i<arr->length; i++)
        cout<<arr->A[i]<<" ";
    cout<<endl;
}

void InsertSort(Array *arr, int key){
    if(arr->length == arr->size)
        return; 
    int i;
    for(i=arr->length-1; arr->A[i]>key && i>=0; i--)
        arr->A[i+1] = arr->A[i];
    arr->A[i+1] = key;
    arr->length++;
}

int IsSorted(Array arr){
    for(int i=0; i<arr.length-1; i++)
        if(arr.A[i] > arr.A[i+1])
            return 0;
    return 1;
}

void ReArrange(Array *arr){
    int i=0, j=arr->length-1;
    while(i < j){
        while(arr->A[i] < 0)
            i++;
        while(arr->A[j] >= 0)
            j--;
        if(i<j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main(){
    Array arr = {{1,2,-3,-4,6}, 10, 5};
    ReArrange(&arr);
    display(&arr);
    return 0;
}