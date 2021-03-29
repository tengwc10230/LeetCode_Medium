/*
Given the root of a binary search tree, and an integer k, 
return the kth (1-indexed) smallest element in the tree.
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
int kthSmallest(TreeNode* root, int k) {
    int output = 0;
    map<int, int> val_cnt;
    queue<TreeNode*>  q;
    q.push(root);
    TreeNode* cur;
    while(!q.empty()){
        cur = q.front();
        if(cur->val != 0)   val_cnt[cur->val] ++;
        q.pop();
        if(cur->left)   q.push(cur->left);
        if(cur->right)  q.push(cur->right);
    }
    for(auto &p : val_cnt){
        k -= p.second;
        if(k <= 0){
            output = p.first;
            break;
        }
    }
    return output;
}
int main(){
    vector<int> tree = {5,3,6,2,4,NULL,NULL,1};
    TreeNode* cur = new TreeNode;
    TreeNode* root = cur;
    queue<TreeNode* >   q_t;
    q_t.push(cur);
    for(int i = 1; i <= tree.size(); i ++){
        cur = q_t.front();
        cur->val = tree[i-1];
        q_t.pop();

        if(i <= tree.size()/2){
            cur->left = new TreeNode;
            q_t.push(cur->left);

            cur->right = new TreeNode;
            q_t.push(cur->right);
        }
    }
    cout << kthSmallest(root, 3) << endl;
}