/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
            ListNode* slow=head, *fast=head;
            // cycle hogi toh kbhi NULL nhi milega
            // fast moves faster, toh fast phle NULL hoga ya last node before NULL hoga
            while(fast!=NULL && fast->next!=NULL){
                    slow=slow->next;
                    fast=fast->next->next;
                    if(fast==slow) return true;
            }
            return false; // here means NULL mila h kahi , ie no loop
    }
};