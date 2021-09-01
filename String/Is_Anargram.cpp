#include<iostream>
#include<string.h>
using namespace std;

// Method 1 is check each element of first array with every element of second array

// Method 2
void isAnargam(char A[], char B[]){
    int n = strlen(A);
    int m = strlen(B);

    if(m != n){
        cout<<"Not Anargam"<<endl;
        return;
    }

    char C[26] = {0};

    for(int i=0; i<n; i++)
        C[(int)A[i] - 97]++;
    for(int i=0; i<m; i++)
        C[(int)B[i] - 97]--;
    for(int i=0; i<25; i++)
        if(C[i] == -1){
            cout<<"Not Anargram"<<endl;
            return;
        }

    cout<<"Anargam"<<endl;
}

int main(){
    char A[] = "medical ";
    char B[] = "decimal";
    isAnargam(A, B);
    return 0;
}