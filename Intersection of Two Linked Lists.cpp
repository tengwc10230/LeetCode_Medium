#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur_A = headA;
    ListNode *cur_B = headB;
    int lenA = 1, lenB = 1;
    if(headA == NULL || headB == NULL)  return NULL;
    else{
        while(cur_A->next || cur_B->next){
            if(cur_A->next){
                cur_A = cur_A->next;
                ++ lenA;
            } 
            if(cur_B->next){
                cur_B = cur_B->next;
                ++ lenB;
            }   
        }
        if(cur_A != cur_B)  return NULL;
        else{
            int diff = lenA - lenB;
            cur_A = headA;
            cur_B = headB;
            while(cur_A != cur_B){
                if(diff > 0){
                    cur_A = cur_A->next;
                    -- diff; 
                }
                else if(diff < 0){
                    cur_B = cur_B->next;
                    ++ diff;
                }
                else{
                    cur_A = cur_A->next;
                    cur_B = cur_B->next;
                }          
            }
            return cur_A;
        }
        
    }
}
int main(){
    ListNode *headA = nullptr;
    ListNode *curA = nullptr;
    ListNode *headB = new ListNode(3);
    ListNode *curB = headB;
    vector<int> nums = {1,9,1,2,4};
    for(auto &p : nums){
        ListNode *node = new ListNode(p);
        if(!headA){
            curA = node;
            headA = curA;
        }
        else{
            curA->next = node;
            curA = curA->next;
            if(node->val == 2)  curB->next = curA;
        }
    }

    ListNode *head = getIntersectionNode(headA, headB);
    ListNode *cur_2 = head;
    
    while(cur_2){
        cout << cur_2->val << " ";
        cur_2 = cur_2->next;
    }
    cout << endl;


}