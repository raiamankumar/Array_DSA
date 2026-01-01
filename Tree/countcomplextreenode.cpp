
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Simple recursive node count
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Build tree from level-order array where -1 represents null
TreeNode* buildFromLevelOrder(const vector<int>& a) {
    if (a.empty() || a[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(a[0]);
    queue<TreeNode*> q; q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)a.size()) {
        TreeNode* cur = q.front(); q.pop();
        // left
        if (i < (int)a.size()) {
            if (a[i] != -1) {
                cur->left = new TreeNode(a[i]);
                q.push(cur->left);
            }
            ++i;
        }
        // right
        if (i < (int)a.size()) {
            if (a[i] != -1) {
                cur->right = new TreeNode(a[i]);
                q.push(cur->right);
            }
            ++i;
        }
    }
    return root;
}

// Read input: first integer m = number of entries, then m integers (use -1 for nulls)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    TreeNode* root = buildFromLevelOrder(a);
    Solution sol;
    cout << sol.countNodes(root) << '\n';
    return 0;
}