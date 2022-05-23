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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt;
            while(curr!=NULL){
                    nxt=curr->next;//its imp to store nxt sbse phle kyuki
                    //baad me after reversing arrow nxt loose ho jayega
                    curr->next=prev; //reversing arrow
                    prev=curr;//prev phle aage shift krna
                    curr=nxt;////then curr aage shift
            }
            //prev will point to last node or newhead
            return prev;
    }
};