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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
         if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        ListNode *fast = head->next, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
            //slow is mid se phle wala node ir (slow->next=mid)
            //for 5 nodes, slow is 2md node
            //for 4 nodes, slow is 2md node (mid is right part)
        TreeNode* root = new TreeNode(slow->next->val);
            cout<<root->val;
        root->right = sortedListToBST(slow->next->next);
        slow->next = NULL; //brking into 2 separate ll before passing left part
        root->left = sortedListToBST(head);
        return root;
    }
};