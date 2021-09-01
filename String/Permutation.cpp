#include<iostream>
using namespace std;

// Method 1
void permutation(char S[], int k){
    static int A[10] = {0};
    static char Res[10];
    int i;
    if(S[k] == '\0'){
        Res[k] = '\0';
        for(int j=0; j<strlen(S); j++)
            cout<<Res[j]<<" ";
        cout<<endl;
    }
    else{
        for(i=0; S[i] != '\0'; i++)
            if(A[i] == 0){
                Res[k] = S[i];
                A[i] = 1;
                permutation(S, k+1);
                A[i] = 0;
            }
    }
}

// Method 2
void Permutation(char S[], int l, int h){
    int i;
    if(l == h){
        for(int j=0; j<=h; j++)
            cout<<S[j]<<" ";
        cout<<endl;
    }
    else{
        for(i=l; i<=h; i++){
            swap(S[l], S[i]);
            Permutation(S, l+1, h);
            swap(S[l], S[i]);
        }
    }
}

int main(){
    char S[] = "ABC";
    Permutation(S,0,2);
    return 0;
}