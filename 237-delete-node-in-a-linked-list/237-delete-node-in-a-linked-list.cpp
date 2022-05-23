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
    void deleteNode(ListNode* node) {
        // if its the last node
            if(node->next==NULL) delete node;
            //prev->next= curr->next krna hai , but node ka prev nhi hai 
            swap(node->val,node->next->val);
            //now node=prev, node->next=curr
            node->next= node->next->next;
    }
};