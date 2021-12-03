#include<iostream>
using namespace std;
#define vi vector<int>

void permute(string str, int i=0){
    if(i==str.length()-1)   cout<<str<<" ";
    else
        for(int j=i; j<str.length(); j++){
            swap(str[i], str[j]);
            permute(str, i+1);
            swap(str[i], str[j]);
        }
}

int main(){
    permute("ABCD");
    cout<<endl;
    return 0;
}