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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if head is the node to be deleted, ie nth node from end 
            // So create dummy node ie prev of head node
            ListNode* dummy= new ListNode(-1);
            dummy->next=head;
            ListNode* slow=head, *fast=head;
            while(n--){
                    fast=fast->next;
            }
            if(fast==NULL) {
                    dummy->next=dummy->next->next; // deleting head
                    return dummy->next;
            }
            while(fast->next!=NULL){
                  slow=slow->next;
                   fast=fast->next;
            }
            // slow ka next is to be deleted
            slow->next=slow->next->next;
            return dummy->next;
    }
};