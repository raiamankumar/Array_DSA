#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           int curr_sum=0;
            for(int j=i;j<n;j++){
                curr_sum += nums[j];

                if(curr_sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=s.subarraySum(arr,target);
    cout<<res;
    return 0;
    

}