#include<iostream>
using namespace std;

int search(int arr[], int n, int x){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == x)   return mid;
        if(arr[low] < arr[mid]){
            if(arr[low] <= x && x < arr[mid])    high = mid - 1;
            else    low = mid + 1;
        } else {
            if(arr[mid] < x && x <= arr[high])   low = mid + 1;
            else    high = mid - 1;
        }
    }
    return -1;
}

int main(){
            //    0  1  2  3  4  5  6  7  8
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3};
    cout<<search(arr, 9, 7)<<endl;
    return 0;
}