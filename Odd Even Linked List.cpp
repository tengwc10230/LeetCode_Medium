/*
Given the head of a singly linked list, group all 
the nodes with odd indices together followed by the 
nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node 
is even, and so on.

Note that the relative order inside both the even and 
odd groups should remain as it was in the input.
*/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)    return head;
    else{
        ListNode *odd_p = head;
        ListNode *even_p = head->next;
        ListNode *even_p_start = head->next;
        bool odd = true;
        ListNode *cur = head->next->next;
        
        while(cur){
            if(odd){
                odd = false;
                odd_p->next = cur;
                odd_p = odd_p->next;
            }
            else{
                odd = true;
                even_p->next = cur;
                even_p = even_p->next;
            }
            cur = cur->next;
        }
        even_p->next = nullptr;
        odd_p->next = even_p_start;
        
        return head;
    }
}

int main(){
    ListNode *head = nullptr;
    ListNode *cur = nullptr;
    vector<int> nums = {1,2,3,4,5};
    for(auto &p : nums){
        ListNode *node = new ListNode(p);
        if(!head){
            cur = node;
            head = cur;
        }
        else{
            cur->next = node;
            cur = cur->next;
        }
    }
    head = oddEvenList(head);
    ListNode *cur_2 = head;
    
    while(cur_2){
        cout << cur_2->val << " ";
        cur_2 = cur_2->next;
    }
    cout << endl;
    
}