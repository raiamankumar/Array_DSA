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
class solution{
    public:
    bool isIdentical(TreeNode*p,TreeNode*q){
        if(p==nullptr || q==nullptr){
            return p==q;
        }

        return isIdentical(p->left,q->left)&&isIdentical(p->right,q->right)&&p->val==q->val;
    }
};
int main(){
     TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    // Build second tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    solution sol;
    if (sol.isIdentical(root1, root2))
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are not identical." << endl;

    return 0;
}

