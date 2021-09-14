#include<iostream>
using namespace std;

void alternate(int arr[], int n){
    int a[n], b[n];
    int j=0,k=0;
    for(int i=0; i<n; i++)
        if(arr[i]>=0)
            a[j++] = arr[i];
        else
            b[k++] = arr[i];
    int i;
    i=j=k=0;
    while(k<n){
        arr[k++] = b[i++];
        arr[k++] = a[j++];
    }
}

int main(){
    int arr[] = {1,-2,8,3,-3,-5,-7};
    alternate(arr, 7);
    for(int i=0; i<7; i++)
        cout<<arr[i]<<" ";
    return 0;
}