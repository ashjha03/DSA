#include<iostream>
using namespace std;

int main(){
    char A[] = "How   are you?";
    int count = 0;
    for(int i=0; A[i] != '\0'; i++)
        if(A[i] == ' ' && A[i-1] != ' ')
            count++;
    cout<<"Words : "<<count+1<<endl;
    return 0;
}