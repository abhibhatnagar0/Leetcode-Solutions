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
          // first k nodes ka kaam hum krenge, baaki recursion krega
            //our work
            ListNode* curr=head, *prev=NULL, *next,*tail=head;
            //tail represents the tail of 1st k nodes
            int i=k-1;
            while(i--){ // k-1 jumps me kth node aayega
                     tail=tail->next;
                    if(tail==NULL) return head; // means size k tk nhi ja pa rha
                                                // so return ll as it is  
            }
            
            while(tail!=prev){ // phle curr==NULL krte the but ab curr k+1 th node pe
                               // aa jayega, not NULL pe
                    next=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=next;
            }
            // now tail=prev =kth node
              head->next=reverseKGroup(curr,k);
            return prev;
            
    }
};