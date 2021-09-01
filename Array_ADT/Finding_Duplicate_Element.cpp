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

// For Sorted Arrays
// Only Finding Duplicate Element
void Duplicate(Array arr){
    int lastDuplicate = 0;
    for(int i=0; i<arr.length; i++)
        if(arr.A[i] == arr.A[i+1] && lastDuplicate != arr.A[i]){
            cout<<"Duplicate Element is : "<<arr.A[i]<<endl;
            lastDuplicate = arr.A[i];
        }
}

//Finding and Counting Duplicate Elements
void CountDuplicate(Array arr){
    int j=0;
    for(int i=0; i<arr.length-1; i++)
        if(arr.A[i] == arr.A[i+1]){
            j = i+2;
            while(arr.A[i] == arr.A[j])
                j++;
            cout<<arr.A[i]<<" : "<<j-i<<endl;
            i = j-1;
        }
}

// For Unsorted Array ** Time Complexity - O(n^2)
void Duplicate_Count(Array arr){
    for(int i=0; i<arr.length-1; i++)
        if(arr.A[i] != -1){
            int count = 1;
            for(int j=i+1; j<arr.length; j++)
                if(arr.A[i] == arr.A[j]){
                    arr.A[j] = -1;
                    count++;
                }
            if(count > 1)
                cout<<arr.A[i]<<" : "<<count<<endl;
        }
}

// Finding and Counting using Hashing --> For Sorted and Unsorted Array ** Time Complexity - O(n)
void Count_Duplicate(Array arr){
    int H[20] = {0};
    for(int i=0; i<arr.length; i++)
        H[arr.A[i]]++;
    for(int i=0; i<20; i++)
        if(H[i] > 1)
            cout<<i<<" : "<<H[i]<<endl;
}

int main(){
    Array arr = {{1,3,6,6,9,11,11,11,13,13,13,13,13}, 10, 13};
    Duplicate_Count(arr);
    return 0;
}