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
            
            ListNode* dummy=new ListNode(-1);
            dummy->next=head;
            
            ListNode*first=head, *second=head->next; 
            ListNode* future= second->next, *prev=dummy;
            
            while(first && second){
                    
                    second->next=first;
                    first->next=future;
                    prev->next=second;
                    
                    prev=first;
                    first=future;
                    if(first==NULL) break;
                    second=first->next;
                    if(second==NULL) {  //for odd number of nodes
                            prev->next=first; // as it is first ko daal do bs
                            break;
                    }
                    future=second->next;
                    
                    
                    
            }
            return dummy->next;
           
            
    }
};