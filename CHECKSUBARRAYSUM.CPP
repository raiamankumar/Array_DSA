#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Map to store {remainder -> first_index_seen}
        unordered_map<int, int> mp;
        
        // Base case: 
        // A remainder of 0 is conceptually seen at index -1.
        // This handles cases where a valid subarray starts from index 0.
        mp[0] = -1;
        
        long long currentSum = 0;
        
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            
            // Calculate remainder
            // If k is large or sum is large, we still just need the remainder
            int remainder = currentSum % k;
            
            // OPTIONAL: Handle negative remainders (if input can be negative)
            // if (remainder < 0) remainder += k;
            
            if (mp.find(remainder) != mp.end()) {
                // If we have seen this remainder before...
                // Get the index where we first saw it
                int prevIndex = mp[remainder];
                
                // Check if the length of the subarray is at least 2
                // Logic: Current Index - First Index >= 2
                if (i - prevIndex >= 2) {
                    return true;
                }
                
                // IMPORTANT: If length is < 2, DO NOT update the map.
                // We want to keep the oldest index (prevIndex) to maximize 
                // the chance of finding a valid length later.
                
            } else {
                // First time seeing this remainder, store it.
                mp[remainder] = i;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    
    if(sol.checkSubarraySum(nums, k)) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;
        
    return 0;
}