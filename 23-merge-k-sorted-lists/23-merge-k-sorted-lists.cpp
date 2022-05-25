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
        
        struct cmp
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp> pq; // min heap
                // saari ll ke heads l1,l2,l3....lk ko pq me daalenege
          ListNode* dummy= new ListNode(-1); // shuru me pq.top() ko iske next me daalenge
          ListNode* tail= dummy; // every time pq.top() ko iske next me daalenege
            for(int i=0;i<lists.size();i++){
                    if(lists[i]!=NULL) pq.push(lists[i]);
            }
          while(!pq.empty()){
                  ListNode* min= pq.top();
                  pq.pop();
                  tail->next=min;
                  tail=min;
                  if(min->next!=NULL) pq.push(min->next);
          }
            return dummy->next;
    }
};