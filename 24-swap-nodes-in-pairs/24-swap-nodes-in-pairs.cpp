/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
         
            ListNode*first=head, *second=head->next; 
            ListNode* future= second->next;
            
            second->next=first;
            first->next=future;
            
             head->next=swapPairs(future);
            
           return second;
            
    }
};