/*
Given two integer arrays preorder and inorder where preorder 
is the preorder traversal of a binary tree and inorder is the 
inorder traversal of the same tree, construct and return the binary tree.
*/
#include <bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, int> mp_inorder;

TreeNode* buildsubTree(vector<int>& preorder, int p_b, int p_e, vector<int>& inorder, int i_b, int i_e){
    TreeNode* child = new TreeNode;
    child->val = preorder[p_b];
    int idx = mp_inorder[preorder[p_b]];
    int len_l = idx - i_b;
    int len_r = i_e - (idx + 1);
    if(len_l)   child->left = buildsubTree(preorder, p_b+1, p_b+1+len_l, inorder, i_b, idx);
    if(len_r)   child->right = buildsubTree(preorder, p_b+1+len_l, p_e, inorder, idx+1, i_e);

    return  child;

}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //找root 切左右子樹
    TreeNode *root = new TreeNode;
    root->val = preorder[0];
    int len = inorder.size();
    mp_inorder.reserve(32768);
    mp_inorder.max_load_factor(0.25);
    for(int i = 0; i < len; i ++)  mp_inorder[inorder[i]] = i;
    int idx = mp_inorder[preorder[0]]; 
    if(idx != 0)    root->left = buildsubTree(preorder, 1, idx+1, inorder, 0, idx);
    if(idx+1 != len)    root->right = buildsubTree(preorder, idx+1, len, inorder, idx+1, len);

    return root;
}

int main(){
    
}
