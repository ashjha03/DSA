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

void Append(Array *arr, int x){
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(Array *arr, int index, int data){
    if(arr->length < arr->size  && index < arr->length){
        for(int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = data;
        arr->length++;
    }
}

int Delete(Array *arr, int index){
    int x = arr->A[index];
    if(index < arr->length && index > 0){
        for(int i = index; i < arr->length; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

int main(){
    Array arr = { {1,2,3,4,5}, 20, 5};
    Append(&arr, 7);
    Insert(&arr, 5, 6);
    display(&arr);

    cout<<"\nDeleted : "<<Delete(&arr, 5)<<endl;
    display(&arr);
    return 0;
}