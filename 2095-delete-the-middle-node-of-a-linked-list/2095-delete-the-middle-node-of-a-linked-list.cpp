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
    ListNode* deleteMiddle(ListNode* head) {
            if(head->next==NULL) return NULL; //only one node
          ListNode* slow=head, *fast=head;
            while(fast!=NULL &&  fast->next!=NULL){
                    slow=slow->next;
                    fast=fast->next->next;
            }
           //slow node represents middle node has to be deleted
           //but slow ka prev node nhi h :(
            if(slow->next==NULL) { //for 2 nodes
                    head->next=NULL;
                    delete slow;
                    return head;
            }
           swap(slow->val,slow->next->val);
            //slow->next has to be deleted now
            slow->next=slow->next->next;
            return head;
    }
};