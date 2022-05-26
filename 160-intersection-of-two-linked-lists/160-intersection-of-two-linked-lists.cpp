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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
            int sizeA=0;
            while(temp!=NULL){
                    sizeA++;
                    temp=temp->next;
            }
            temp=headB;
             int sizeB=0;
            while(temp!=NULL){
                    sizeB++;
                    temp=temp->next;
            }
            if(sizeA==0 || sizeB==0) return NULL;
            ListNode* p1=headA;
            ListNode* p2=headB;
            if(sizeA>sizeB){
                   int p=sizeA-sizeB;
                   while(p--) p1=p1->next;
            }
            else if(sizeB>sizeA){
                     int p=sizeB-sizeA;
                   while(p--) p2=p2->next;
            }
            while(p1!=p2){
                    if(p1==NULL || p2==NULL) return NULL;
                    p1=p1->next;
                    p2=p2->next;
            }
            return p1; 
    }
};