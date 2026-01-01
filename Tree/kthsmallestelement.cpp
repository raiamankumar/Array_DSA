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
    int count = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);

        if (result != -1) return; // early exit if found
        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        result = -1;
        inorder(root, k);
        return result;
    }
};

// Insert value into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // m
    // v1 v2 ... vm   (values to insert into BST in this order)
    // k
    int m;
    if (!(cin >> m)) return 0;
    vector<int> vals(m);
    for (int i = 0; i < m; ++i) cin >> vals[i];
    int k; cin >> k;

    TreeNode* root = nullptr;
    for (int v : vals) root = insertBST(root, v);

    Solution sol;
    int ans = sol.kthSmallest(root, k);
    if (ans == -1) cout << "k is out of range\n";
    else cout << ans << '\n';
    return 0;
}