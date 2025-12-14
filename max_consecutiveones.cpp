#include<bits/stdc++.h>
using namespace std;

int consecutive_one(vector<int>&nums){
    int count=0;
    int max_count=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
            max_count++;
        }
        else{
            count=0;
            max_count=max(count,max_count);
          // max_count++;
        
        }
    }
    return max_count;
}
int main(){
    int n;
    //cout<<"enter the no of element:";
    cin>>n;
    vector<int>arr(n);
   // cout<<"enter the element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< consecutive_one(arr);
}