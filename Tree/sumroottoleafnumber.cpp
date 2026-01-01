#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Your solution class
class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (!root) return 0;

        current = current * 10 + root->val;

        if (!root->left && !root->right) {
            return current;
        }

        int leftsubtree = dfs(root->left, current);
        int rightsubtree = dfs(root->right, current);

        return leftsubtree + rightsubtree;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

// Driver code
int main() {
    /*
           1
          / \
         2   3
    Paths: 12, 13 → Sum = 25
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Sum of root-to-leaf numbers: " << sol.sumNumbers(root) << endl;

    /*
           4
          / \
         9   0
        / \
       5   1
    Paths: 495, 491, 40 → Sum = 1026
    */

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(0);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(1);

    cout << "Sum of root-to-leaf numbers: " << sol.sumNumbers(root2) << endl;

    return 0;
}