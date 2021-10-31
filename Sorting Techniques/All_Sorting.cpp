#include<iostream>
using namespace std;
#define rep(i,j,n) for(int i=j; i<n; i++)

void bubbleSort(int arr[], int n){
    rep(i,0,n)
        rep(j,0,n-1-i)
            if(arr[j+1] < arr[j])    swap(arr[j+1], arr[j]);
}

void insertionSort(int arr[], int n){
    rep(i,1,n){
        int j = i-1;
        int x = arr[i];
        while(arr[j] > x and j>-1){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

void selectionSort(int arr[], int n){
    int k, j;
    rep(i,0,n){
        k = j = i;
        rep(j,i,n)
            if(arr[j] < arr[k]) k = j;
        swap(arr[i], arr[k]);
    }
}

int Partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l, j = h;
    do{
        do{i++;}while(pivot >= arr[i]);
        do{j--;}while(pivot < arr[j]);
        if(i<j) swap(arr[i], arr[j]);
    }while(i<j);
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h){
    if(l<h){
        int mid = Partition(arr, l, h);
        quickSort(arr, l, mid);
        quickSort(arr, mid+1, h);
    }
}

void Merge(int arr[], int l, int mid, int h){
    int temp[h-l+1];
    int i=l, j=mid+1, k=0;
    while(i<=mid and j<=h){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else    temp[k++] = arr[j++];
    }
    while(j<=h){
        temp[k++] = arr[j++];
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    rep(i,l,h+1){
        arr[i] = temp[i-l];
    }
}

void mergeSort(int arr[], int n){
    int p, i, l, mid, h;
    for(p=2; p<=n; p*=2){
        for(i=0; i+p-1<n; i+=p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(arr, l, mid, h);
        }
    }
    if(p/2 < n)
        Merge(arr, 0, p/2-1, n-1);
}

int main(){
    int arr[] = {8, 3, 4, 7, 9, 2, 6, 1, 5};
    rep(i,0,9)
        cout<<arr[i]<<" ";
    cout<<endl;
    mergeSort(arr, 9);
    // quickSort(arr, 0, 9);
    rep(i,0,9)
        cout<<arr[i]<<" ";
    return 0;
}