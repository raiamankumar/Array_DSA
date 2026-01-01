#include<bits/stdc++.h>
using namespace std;
class TreeNode{
   public:
   int val;
   TreeNode*left;
   TreeNode*right;
   //constructor
   TreeNode(int data){
    val=data;
    left=right=nullptr;
   }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
              return true;
        if (t1 == nullptr || t2 == nullptr) 
              return false;

              return (t1->val == t2->val) &&
                  isMirror(t1->left, t2->right) &&
                  isMirror(t1->right, t2->left);
    }
};
int main(){
   TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution sol;
    if (sol.isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;

}