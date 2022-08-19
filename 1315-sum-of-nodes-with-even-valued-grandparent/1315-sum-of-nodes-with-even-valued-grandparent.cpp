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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        dfs(root,NULL,NULL,sum);
        return sum;
    }
    void dfs(TreeNode* node,TreeNode* parent,TreeNode* grandparent, int &sum){
        if(grandparent!=NULL && grandparent->val %2 ==0){
            sum+=node->val;
        }
        if(node->left) dfs(node->left,node,parent,sum);
        if(node->right) dfs(node->right,node,parent,sum);
    }
};