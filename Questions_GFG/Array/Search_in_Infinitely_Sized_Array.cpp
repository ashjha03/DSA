#include <iostream>
using namespace std;

int search(int arr[], int x){  // Naive Method
	int i = 0;
	while(true){
		if(arr[i] == x) return i;
		if(arr[i] > x) return -1;
		i++;
	}
}

int binarySearch(int arr[], int low, int high, int x){
    while (low <= high) {
        int mid = (low + high) / 2;
        if(x == arr[mid])    return mid;
        else if(arr[mid] < x)   low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int Search(int arr[], int x){ // Efficient Method
    if(arr[0] == x) return 0;
    int i=1;
    while(arr[i] < x)   i *= 2;
    if(arr[i] == x) return i;
    return binarySearch(arr, i/2+1, i-1, x);
}

int main() {    
    int arr[] = {1, 2, 3, 5, 7};
	int x = 5;
	cout << search(arr, x) << endl;
	cout << Search(arr, x) << endl;
	return 0;
}