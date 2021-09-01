#include<iostream>
using namespace std;

int main(){
    char *s = "Welcome";
    int i;
    for(i=0; s[i] != '\0'; i++){}
    cout<<"Length : "<<i<<endl;

    return 0;
}