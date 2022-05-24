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
        ListNode* dummy= new ListNode(-1);
        ListNode* tail=dummy; // tail ke aage l1,l2 ka smaller node append hoga
            while(list1!=NULL && list2!=NULL){
                    if(list1->val < list2->val){
                            tail->next=list1;
                            tail=tail->next;
                            list1=list1->next;
                    }
                    else{
                            tail->next=list2;
                            tail=tail->next;
                            list2=list2->next;        
                    }
            }
            //any one or both of l1 l2 will become 0
            if(list1==NULL) tail->next=list2;
            if(list2==NULL) tail->next=list1;
            return dummy->next;
            
    }
};