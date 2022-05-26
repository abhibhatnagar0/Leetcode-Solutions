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
        ListNode* reverse(ListNode* head){
                if(head==NULL || head->next==NULL) return head;
                ListNode* curr=head, *prev=NULL, *next;
                while(curr!=NULL){
                        next=curr->next;
                        curr->next=prev;
                        prev=curr;
                        curr=next;
                }
                return prev;
        }
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return NULL;
         if(head->next==NULL) return true;
            // for even length of ll, middle node se reverse nikalenge
            // for odd length of ll, middle->next se reverse nikalenge
            ListNode* slow= head, *fast=head;
            while(fast->next!=NULL && fast->next->next!=NULL){
                    slow=slow->next;
                    fast=fast->next->next;
            }
           //fast NULL hota h for even length, when slow is middle node
           //fast->next NULL hota h for odd length, when slow is middle node
            //here slow is node earlier to middle node (for attachment purpose)
            slow->next=reverse(slow->next);
            ListNode* start=head, *middle=slow->next;
            //keep comparing nodes from start and middle
            while(middle!=NULL){
                    if(start->val != middle->val) return false;
                    start=start->next;
                    middle=middle->next;
            }
            return true;
            
    }
};