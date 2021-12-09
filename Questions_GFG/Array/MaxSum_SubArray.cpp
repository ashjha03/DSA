#include<iostream>
using namespace std;

int maxSum(int arr[], int n){
    int res = arr[0], maxEnding = arr[0];
    for(int i = 1; i < n; i++) {
        maxEnding = max( maxEnding+arr[i], arr[i] );
        res = max(res, maxEnding);
    }
    return res;
}

int main(){
    // int arr[] = {1,-2,3,-1,2};
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Max Sum is: "<<maxSum(arr, 9)<<endl;
    return 0;
}