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
    ListNode* sortList(ListNode* head) {
          if(head == NULL || head ->next == NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
		
//( NOTE: in merge sort , it doesnt matter wheTher u have extra node in ist or 2nd half ( in case of odd no. of total nodes)
            // even length me equal nodes shld be there on both sides 
            //so for 4 nodes, mid/slow= 2nd node not 3rd
         
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next; // so that even nodes me slow phle wala mid ho
        }
        ListNode*left=head;
        ListNode*right=slow->next;
        slow->next=NULL; //breaking 2 lls so as to individually apply merge sort on them
            
        ListNode* l1=sortList(left);
        ListNode* l2=sortList(right);
        return merge(l1,l2);
    }
    ListNode* merge(ListNode *l1, ListNode *l2){
              ListNode* dummy=new ListNode(0);
              ListNode* tail=dummy;
              while(l1!=NULL && l2!=NULL){
                  if(l1->val < l2->val){
                      tail->next=l1;
                      l1=l1->next;
                    }
                  else{
                      tail->next=l2;
                      l2=l2->next;
                   }
                  tail=tail->next;
                }
             if(l1==NULL) tail->next=l2; 
             if(l2==NULL) tail->next=l1;   
         return dummy->next;
     }
    
};