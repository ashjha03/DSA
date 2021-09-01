#include<iostream>
using namespace std;

// Method 1 --> With use of another string
// char *Reverse(char *A){
//     char *s = new char[9];
//     int i;
//     for(i=0; A[i] != '\0'; i++){}
//     i--;
//     for(int j=0; i>=0; i--,j++)
//         s[j] = A[i];
//     return s;

// }

// // Method 2 --> By swapping characters
void Rev(char A[]){
    int i;
    for(i=0; A[i]!='\0'; i++){}
    i--;
    for(int j =0; j<i; j++,i--){
        char temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }

}

int main(){
    char A[10] = "Python";
    Rev(A);
    for(int i=0; A[i] != '\0'; i++)
        cout<<A[i];
    cout<<endl;

    return 0;
}