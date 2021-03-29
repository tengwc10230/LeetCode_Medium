/*
Given the root of a binary tree, return the zigzag level order 
traversal of its nodes' values. (i.e., from left to right, then 
right to left for the next level and alternate between).


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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> output;
    if(!root)   return output;
    else {
        queue<TreeNode *> Q_t;
        queue<TreeNode *> q_t;
        q_t.push(root);

        bool even_level = false;
        while(!Q_t.empty() || !q_t.empty()){
            vector<int> each_level = {};
            while(!q_t.empty()){
                Q_t.push(q_t.front());
                each_level.push_back(q_t.front()->val);
                q_t.pop();
            }
            
            if(even_level)  reverse(each_level.begin(), each_level.end());
            output.push_back(each_level);
            even_level = !even_level;
            
            while(!Q_t.empty()){
                TreeNode *cur = Q_t.front();
                Q_t.pop();
                if(cur->left)   q_t.push(cur->left);
                if(cur->right)  q_t.push(cur->right);
            }
            
        }
    } 
    return output;
}

int main(){
    vector<int> tree = {3,9,20,NULL,NULL,15,7};
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
            cur->right = new TreeNode;
            q_t.push(cur->left);
            q_t.push(cur->right);
        }
    }
    vector<vector<int>> output = zigzagLevelOrder(root);
    for(auto &v_p : output){
        cout << '[' ;
        for(auto &p : v_p)  cout << p << " ";
        cout << '\b' << ']' << endl;
    }
    //Input: root = [3,9,20,null,null,15,7]
    //Output: [[3],[20,9],[15,7]]
}