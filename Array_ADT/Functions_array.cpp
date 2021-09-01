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

int Get(Array *arr, int index){
    if(index>=0 && index<arr->length)
        return arr->A[index];
    return -1;
}

void Set(Array *arr, int index, int value){
    if(index>=0 && index<arr->length)
        arr->A[index] = value;
}

int Max(Array *arr){
    int max = arr->A[0];
    for(int i=1; i<arr->length; i++)
        if(max < arr->A[i])
            max = arr->A[i];
    return max;
}

int Min(Array *arr){
    int min = arr->A[0];
    for(int i=1; i<arr->length; i++)
        if(min > arr->A[i])
            min = arr->A[i];
    return min; 
}

int Sum(Array *arr){
    int sum = 0;
    for(int i=0; i<arr->length; i++)
        sum += arr->A[i];
    return sum;
}

float Avg(Array *arr){
    float sum = Sum(arr);
    return ( sum / ( (float)arr->length) ); 
}

int main(){
    Array arr = {{1,2,3,4,5}, 10, 5};
    Set(&arr, 2, 6);

    cout<<"Max : "<<Max(&arr)<<"\nMin : "<<Min(&arr)<<"\nAvg : "<<Avg(&arr)<<endl;

    display(&arr);
    return 0;
}