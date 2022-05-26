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
    ListNode *detectCycle(ListNode *head) {
            if(head==NULL || head->next==NULL) return NULL;
          bool cycleExists=false;
            ListNode* slow=head, *fast=head;
            while(fast!=NULL && fast->next!=NULL){
                    slow=slow->next;
                    fast=fast->next->next;
                    if(fast==slow){
                            cycleExists=true;
                            break;
                    }
            }
            if(cycleExists==false) return NULL;
            
                    // head to node where cycle begins distance is same as distance of that node to node of intersection of fast and slow.
                    fast=head;
                    while(fast!=slow){
                            slow=slow->next;
                            fast=fast->next;
                    }
                    //here fast=slow , so this node is desired node.
                    return slow; //=fast  
    }
};