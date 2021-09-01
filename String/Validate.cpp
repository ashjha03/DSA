#include<iostream>
using namespace std;

int main(){
    char A[] = "Ashishjha.03";
    bool b = true;
    for(int i=0; A[i] != '\0'; i++)
        if( !(A[i] >= 65 && A[i] <= 90) && !(A[i]>=97 && A[i] <=122) && !(A[i]>=48 && A[i] <=57)){
            b = false;
            break;
        }
    if(b)
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
        
    return 0;
}