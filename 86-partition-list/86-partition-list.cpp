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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyA= new ListNode(-1); // smaller than x aage aayenge
            ListNode* tailA=dummyA;
        ListNode* dummyB =new ListNode(-1); // x or greater than x aayenge
            ListNode* tailB=dummyB;
            while(head!=NULL){
                    if(head->val < x){
                            tailA->next=head;
                            tailA=head;
                    }
                    else{
                            tailB->next=head;
                            tailB=head;
                    }
                    head=head->next;
            }
            tailA->next=dummyB->next;
            tailB->next=NULL;
            return dummyA->next;
    }
};