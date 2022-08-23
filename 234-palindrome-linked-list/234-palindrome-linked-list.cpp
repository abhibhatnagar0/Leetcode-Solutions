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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        if(head->next==NULL) return true;
        ListNode* mid= middle(head);
        ListNode* l1= head, *l2=mid->next;
        mid->next=NULL;
        l2= reverse(l2);
        bool flag= compare(l1,l2);
        l2= reverse(l2);
        mid->next=l2;
        return flag;
    }
    ListNode* reverse(ListNode* head){
       if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL,*curr=head,*temp;
        while(curr){
            temp= curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool compare(ListNode* l1, ListNode* l2){
        while(l1 && l2){
          if(l1->val !=l2->val) return false;
            l1=l1->next;
            l2=l2->next;
         }
        return true;
    }
    ListNode* middle(ListNode* head){
        ListNode* slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};