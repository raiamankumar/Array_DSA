#include<bits/stdc++.h>
using namespace std;

void subArray(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            cout<<"{";
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<"}";
        }
    }
}
int main(){
    int n;
    cout<<"enter the no of element:";
    cin>>n;
    vector<int>arr(n);
    cout<<"element are :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subArray(arr);

  return 0;
}