#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
   int val;
   TreeNode*left;
   TreeNode*right;

   TreeNode(int data){
    val=data;
    left=right=nullptr;
   }
};
class Solution{
    public:
    int height(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int leftheight=height(root->left);
        int rightheight=height(root->right);

        return max(leftheight,rightheight)+1;
    }
    int diameter(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int leftdiameter=diameter(root->left);
        int rightdiameter=diameter(root->right);

        int currdiameter=height(root->left)+height(root->right)+1;

        return max(currdiameter,max(leftdiameter,rightdiameter));
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of the tree: " << sol.diameter(root) << endl;

    return 0;
}

