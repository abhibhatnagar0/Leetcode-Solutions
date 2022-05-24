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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1==NULL) return list2;
            if(list2==NULL) return list1;
        ListNode* head =new ListNode();
            ListNode* p1=list1, *p2=list2, *p3=head;
            while(p1!=NULL && p2!=NULL){
                    if(p1->val < p2->val){
                            p3->val=p1->val;
                            p1=p1->next;
                    }
                    else{
                            p3->val=p2->val;
                            p2=p2->next;
                    }
                    p3->next= new ListNode();
                    p3=p3->next;
            }
            if(p1==NULL && p2!=NULL){
                    while(p2!=NULL){
                            p3->val=p2->val;
                            p2=p2->next;
                            if(p2==NULL) {
                                    p3->next=NULL;
                                    return head; }
                            p3->next= new ListNode();
                            p3=p3->next;     
                    }
            }
             if(p2==NULL && p1!=NULL){
                    while(p1!=NULL){
                            p3->val=p1->val;
                            p1=p1->next;
                            if(p1==NULL) { 
                                    p3->next=NULL;
                                    return head; }
                            p3->next= new ListNode();
                            p3=p3->next;     
                    }
            }
            return head;
            
    }
};