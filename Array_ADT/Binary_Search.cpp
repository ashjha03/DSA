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

// Iterative Version
int Binary_Search(Array *arr, int key){
    int l = 0, h = arr->length - 1;
    int mid;
    while(l <= h){
        mid = ( l + h ) / 2;
        if(arr->A[mid] == key)
            return mid;
        else if(arr->A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Recusive Version
int BinSearch(Array *arr, int l, int h, int key){
    int mid;
    while(l <= h){
        mid = ( l + h ) / 2;
        if(arr->A[mid] == key)
            return mid;
        else if(arr->A[mid] > key)
            BinSearch(arr, l, mid - 1, key);
        else
            BinSearch(arr, mid + 1, h, key);
    }
    return -1;
}

void display(Array *arr){
    for(int i=0; i<arr->length; i++)
        cout<<arr->A[i]<<" ";
}

int main(){
    Array arr = { {1,2,3,4,5}, 10, 5};
    cout<<"Element found at index : "<<BinSearch(&arr, 0, 5, 3);
    return 0;
}