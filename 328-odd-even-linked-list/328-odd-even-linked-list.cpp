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
    ListNode* oddEvenList(ListNode* head) {
            if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head;
            ListNode* even=head->next, *temp=even;
            // head is initial odd node
            //temp stores initial node of even as it is to be attached after last odd node
            while(even!=NULL && even->next!=NULL){
               //for odd length even will become NULL
               //for even length even->next will become NULL
                    odd->next=even->next;
                    odd=odd->next;
                    
                    even->next=odd->next;
                    even=even->next;
            }
            odd->next=temp;
          
            return head;
            
    }
};