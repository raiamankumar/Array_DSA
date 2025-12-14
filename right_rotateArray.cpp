#include<bits/stdc++.h>
using namespace std;

void right_rotateArray(vector<int>&arr,int n,int k){
    k=k%n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[n-k + i];
}
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    right_rotateArray(arr,n,k);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}
