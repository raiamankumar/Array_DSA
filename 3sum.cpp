#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> res = threeSum(arr);

    // Print result
    for (auto triplet : res) {
        for (auto x : triplet) cout << x << " ";
        cout << endl;
    }
}