#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    unordered_map<int, int> inorderIndex; // map value -> index in inorder
    int preorderPos = 0; // current index in preorder

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return NULL;

        // Root is current element in preorder
        int rootVal = preorder[preorderPos++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int mid = inorderIndex[rootVal];

        // Recursively build left and right subtrees
        root->left = build(preorder, inorder, left, mid - 1);
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store inorder indices in hashmap for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
int main(){
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = sol.buildTree(preorder, inorder);
    // The tree is now built. Print preorder to verify structure.
    function<void(TreeNode*)> printPreorder = [&](TreeNode* node){
        if (!node) return;
        cout << node->val << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    };

    printPreorder(root);
    cout << "\n";
    return 0;
}