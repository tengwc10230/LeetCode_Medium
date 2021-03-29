/*
You are given a perfect binary tree where all leaves are on the 
same level, and every parent has two children. 
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/
#include <bits/stdc++.h>

using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>  q;
        q.push(root);
        Node* cur = root;
        while(!q.empty()){
            int q_len = q.size();
            for(int i = 0; i < q_len; i ++){
                cur = q.front();
                q.pop();
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
                if(i != q_len-1)    cur->next = q.front();
            }
        }
        
        return root;
    }
};