#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findCelebrity(int n) {
        vector<vector<int>> knows_matrix(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> knows_matrix[i][j];
            }
        }

        int candidate = 0;
        for(int i = 1; i < n; ++i){
            if(knows_matrix[candidate][i] == 1){
                candidate = i;
            }
        }

        for(int i = 0; i < n; ++i){
            if(i != candidate){
                if(knows_matrix[candidate][i] == 1 || knows_matrix[i][candidate] == 0){
                    return -1;
                }
            }
        }

        return candidate;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    Solution sol;
    int result = sol.findCelebrity(n);
    cout << result << '\n';

    return 0;
}