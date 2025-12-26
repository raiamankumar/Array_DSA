#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data=val;
        left=right=nullptr;
}
};
class Solution{
    public:
    int count(Node*root){
        if(root==nullptr){
            return 0;
        }
    int leftcount=count(root->left);
    int rightcount=count(root->right);

    int ans=leftcount+rightcount+1;

    return ans;
    }
};
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Number of nodes in the tree: " << sol.count(root) << endl;

    return 0;
}

