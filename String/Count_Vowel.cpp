#include<iostream>
using namespace std;

int main(){
    char A[] = "How are you?";
    int v_count = 0, c_count = 0;
    for(int i=0; A[i] != '\0'; i++)
        if(A[i] == 'A' || A[i] == 'a' || A[i] == 'E' || A[i] == 'e' || A[i] == 'I' || A[i] == 'i' || A[i] == 'O' || A[i] == 'o' || A[i] == 'U' || A[i] == 'u' )
            v_count++;
        else if((A[i] >= 65 && A[i] <= 90) || (A[i]>=97 && A[i] <=122))
            c_count++;
        
        cout<<"Vowels : "<<v_count<<"\nConsonants : "<<c_count<<endl;
    return 0;
}