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

Array *Merge(Array *arr1, Array *arr2){
    int i=0, j=0, k=0;
    Array *arr3 = new Array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for( ; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for( ; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;
    return arr3;
}

int main(){
    Array arr1 = {{1,3,5,7,9}, 10, 5};
    Array arr2 = {{2,4,6,8,10}, 10, 5};
    Array *arr3 = Merge(&arr1, &arr2);

    display(arr3); 
    return 0;
}