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
    ListNode* removeElements(ListNode* head, int val) {
            if(head==NULL) return head;
            ListNode* dummy= new ListNode(-1);
            dummy->next=head;
            // starting ke nodes if has value = val, then usko del krke head change krna pdega
            //baar baar
            // so dummy bnaya h before head
            // jisse same condition rhe for all nodes
            //condn: temp stores node jiska next node is to be deleted. 
        ListNode* temp=dummy;
            while(temp->next!=NULL){
                    if(temp->next->val==val){
                            temp->next=temp->next->next;
                    }
                    else temp=temp->next;
            }
            return dummy->next;
    }
};