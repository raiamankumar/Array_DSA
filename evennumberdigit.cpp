<<<<<<< HEAD
//find the number with even number of digit
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool numsEvenDigit(int nums) {
        int digitcnt = 0;
        while (nums != 0) {
            nums = nums / 10;
            digitcnt++;
        }
        return digitcnt % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int evencnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (numsEvenDigit(nums[i])) {
                evencnt++;
            }
        }
        return evencnt;
    }
};

int main() {
    int n;
    cin >> n;  
    vector<int> temp(n);
    
    for (int i = 0; i < n; i++) {
        cin >> temp[i];  
    }

    Solution s;
    int res = s.findNumbers(temp);
    cout << res << endl;  
    return 0;
=======
//find the number with even number of digit
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool numsEvenDigit(int nums) {
        int digitcnt = 0;
        while (nums != 0) {
            nums = nums / 10;
            digitcnt++;
        }
        return digitcnt % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int evencnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (numsEvenDigit(nums[i])) {
                evencnt++;
            }
        }
        return evencnt;
    }
};

int main() {
    int n;
    cin >> n;  
    vector<int> temp(n);
    
    for (int i = 0; i < n; i++) {
        cin >> temp[i];  
    }

    Solution s;
    int res = s.findNumbers(temp);
    cout << res << endl;  
    return 0;
>>>>>>> 9777ce9275c4f8345e3c897d7d500b9f70545c62
}