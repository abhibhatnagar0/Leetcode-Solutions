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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i;
        ListNode* dummy=new ListNode;
        dummy->next=head;
        ListNode* lastleft= dummy;
        ListNode* curr=head;//Copying so that original head isnt lost
        for(i=1; i< left ;i++){
            lastleft=curr;
            curr=curr->next;
        }
        //Reversal starts here
        ListNode *prev = NULL,*next=NULL;//Yes I am using an extra pointer next which could have been avoided,but I will do whatever I want XD
        while(i<=right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
     lastleft->next->next=curr;
     lastleft->next=prev;
     return dummy->next;
    }
};