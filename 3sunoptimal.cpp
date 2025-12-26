#include <iostream>

#include <vector>
#include <algorithm> // Required for sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if (n < 3) {
            return ans;
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                // Use long long to prevent overflow
                long long sum = (long long)nums[i] + (long long)nums[left] + (long long)nums[right];
                
                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    // 1. Setup Input
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 2. Create Object and Call Function
    Solution s; 
    vector<vector<int>> result = s.threeSum(nums);

    // 3. Print the Output
    cout << "Triplets found:" << endl;
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << "[";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if(j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}