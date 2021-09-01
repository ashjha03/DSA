#include <iostream>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void IterativeMergeSort(int A[], int n){
    int i, p, l, mid, h;
    for(p=2; p<=n; p*=2)
        for(i=0; i+p-1<n; i+=p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A, i, mid, h);
        }
    
    if(p/2<n) // For odd no. of elements
        Merge(A, 0, p/2, n-1);
}

void RecursiveMergeSort(int A[], int low, int high){
    if (low < high){
        // Calculate mid point
        int mid = low + (high-low)/2;

        // Sort sub-lists
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid+1, high);

        // Merge sorted sub-lists
        Merge(A, low, mid, high);
    }
}

int main(){
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);

    Print(A, n, "\t\t    A");
    RecursiveMergeSort(A, 0, n-1);
    Print(A, n, " Recursively Sorted A");

    IterativeMergeSort(A,n);
    Print(A, n, " Iteratively Sorted A");

    return 0;
}