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
         if(head==NULL) return NULL;
        vector<int>v;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
            int n=v.size();
        return makeBst(v,0,n-1); //make bst from values of idxs 0 to n-1 (inclusive)
    }
        
         TreeNode* makeBst(vector<int>v,int l,int r)
        {
        if(l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = makeBst(v,l,mid-1);
        root->right = makeBst(v,mid+1,r);
        
        return root;
        }
};