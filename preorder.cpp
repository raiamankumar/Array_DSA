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
static int idx=-1;
Node* Buildtree(vector<int>preorder){
     idx++;
    if(preorder[idx]==-1){
        return nullptr;
    }
    Node*root = new Node(preorder[idx]);
    root->left=Buildtree(preorder);
    root->right=Buildtree(preorder);

    return root;


}
