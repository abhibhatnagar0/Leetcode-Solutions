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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL|| k==1) return head;
            // after reversing a grp of k nodes, start and end connections are to be made
            ListNode* beforeStart, *afterTail;
            ListNode* dummy= new ListNode(-1);
            beforeStart=dummy;
            dummy->next=head;
            ListNode* curr=head, *prev=dummy, *next, *tail=head,*start;
            int i=1;
            while(tail!=NULL){
                    if(i%k!=0){
                            tail=tail->next;
                    }
                    else{  afterTail=tail->next;
                           start=curr;
                         //reverse here as tail is end of k nodes, curr is start
                         while(prev!=tail){
                                 next=curr->next;
                                 curr->next=prev;
                                 prev=curr;
                                 curr=next;
                         }
                            beforeStart->next=tail;
                            start->next=afterTail;  
                            beforeStart=start;
                            tail=afterTail; //=curr=next
                    }
                    i++;
            }
        return dummy->next;    
    }
};