#include<iostream>
#include<vector>
using namespace std;
#define vi vector<int>
#define rep(i,j,n) for(int i=j; i<n; i++)

int countSum(vi &v, vi res, int k, int i){
    if(i >= v.size()){
        int sum = 0;
        for(int j=0; j<res.size(); j++)    sum += res[j];
        if(sum == k)    return 1;
        else return 0;
    }
    int l = 0, r = 0;
    l += countSum(v,res,k,i+1);
    res.push_back(v[i]);
    r += countSum(v,res,k,i+1);
    return l+r;
}

int cs(int arr[], int n, int sum){
    if(!n)  return (!sum) ? 1 : 0;
    return cs(arr, n-1, sum) + cs(arr, n-1, sum-arr[n-1]);
}

int main(){
    vi v, ans;
    v.push_back(10);v.push_back(20);v.push_back(5),v.push_back(7),v.push_back(8);
    cout<<countSum(v, ans, 15, 0)<<endl;
    int arr[] = {10,20,5,7,8};
    cout<<cs(arr,5,15)<<endl;
    return 0;
}