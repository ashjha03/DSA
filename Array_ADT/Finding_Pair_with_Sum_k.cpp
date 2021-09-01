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

// For Sorted Array
void FindPair(Array arr, int sum){
    int i=0, j=arr.length-1;
    while(i < j){
        if(arr.A[i] + arr.A[j] == sum){
            cout<<"Pair : ( "<<arr.A[i]<<" , "<<arr.A[j]<<" )"<<endl; 
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < sum)
            i++;
        else
            j--;
    }
}

// For Unsorted Array
void Pair(Array arr, int sum){
    for(int i=0; i<arr.length; i++)
        for(int j=i+1; j<arr.length; j++)
            if(arr.A[i] + arr.A[j] == sum)
                cout<<"Pair : ( "<<arr.A[i]<<" , "<<arr.A[j]<<" )"<<endl; 
}

void Pair_Hashing(Array arr, int sum){
    int H[20] = {0};
    for(int i=0; i<arr.length; i++){
        if(H[sum - arr.A[i]])
            cout<<"Pair : ( "<<arr.A[i]<<" , "<<sum - arr.A[i]<<" )"<<endl; 
        H[arr.A[i]] = 1;
    }
}

int main(){
    Array arr = {{1,3,5,7,9}, 10, 5};
    FindPair(arr, 10);
    return 0;
}