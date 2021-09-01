#include<iostream>
#include<string.h>
using namespace std;

// ***** This CODE is totally CASE SENSITIVE *****

void check(char A[], char B[]){
    int i,j, result = 0;
    for( i=0, j=0; A[i] != '\0' && B[i] != '\0'; i++, j++)
        if(A[i] != B[j]){
            if(A[i] > B[j])
                result = 2;
            if(A[i] < B[j])
                result = 1;
            break;
        }

    if(strlen(A) > strlen(B) && result == 0)
        result = 2;
    if(strlen(B) > strlen(A) && result == 0)
        result = 1;

    switch (result)
    {
    case 0: cout<<"Same strings"<<endl;
        break;
    
    case 1: cout<<"1st is smaller"<<endl;
        break;
    
    case 2: cout<<"2nd is smaller"<<endl;
        break;
    }
}

char *Reverse(char A[]){
    int n = strlen(A);
    char *B = new char[n];
     for(int i=0; i<n; i++)
        B[i] = A[n-i-1];
    return B;
}

// Method 2
void Palindrome2(char A[]){
    int count = 0;
    char *B = Reverse(A);
    for(int i=0; i<strlen(A); i++)
        if(B[i] != A[i]){
            count++;
            cout<<"Not Palindrome"<<endl;
            break;
        }
    
    if(count == 0)
        cout<<"Palindrome"<<endl;
}

// Method 1
void Palindrome1(char A[]){
    int i=0, j=strlen(A)-1, count = 1;
    while(i<j)
        if(A[i++] != A[j--]){
            cout<<"Not Palindrome"<<endl;
            count--;
            break;
        }
    if(count)
        cout<<"Palindrome"<<endl;
}

int main(){
    char A[] = "Painter";
    char B[] = "Painting";
    // check(A,B);

    char C[] = "naman";
    Palindrome1(C);
    
    return 0;
}