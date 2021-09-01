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

void Miss(Array arr){
    int diff = arr.A[0];
    for(int i=0; i<arr.length; i++)
        if(arr.A[i] - i != diff){
            cout<<"Missing Element is : "<<i + diff<<endl;
            break;
        }
}

// If Elements starts from 1 onwards
void Missing(Array arr){
    int sum = 0, i;
    for(i = 0; i < arr.length; i++)
        sum += arr.A[i];
    int actual_sum = (i * (i+1)) / 2;
    cout<<"Missing Element is : "<<actual_sum - sum<<endl;
}

// If multiple elements are missing
void Multiple_Miss(Array arr){
    int diff = arr.A[0];
    for(int i=0; i<arr.length; i++)
        if(arr.A[i] - i != diff)
            while(diff < arr.A[i] - i){
            cout<<"Missing Element is : "<<i + diff<<endl;
            diff++;
        }
}

// ***** IF ELEMENTS ARE NOT SORTED ***** --> Above all functions are for sorted arrays
void Find_Miss(Array arr, int h){ // h stands for highest value in array
    int temp[14] = {0}; // Here Initialization is must, otherwise some are taking garbage value. Hence, temp[h+1] cannot be used because we cannot do initialization there.

    //************** This TECHNIQUE is known HASHING *************
    for(int i=0; i<arr.length; i++)
        temp[arr.A[i]] = 1;

    for(int i=1; i<=h; i++)
        if(!temp[i])
            cout<<"Missing Element is : "<<i<<endl;
}

int main(){
    Array arr = {{1,3,6,13,9,11}, 10, 6};
    Find_Miss(arr, 13);
    return 0;
}