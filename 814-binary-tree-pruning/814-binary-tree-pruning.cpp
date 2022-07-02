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
    //har leaf node pe 0 hai toh usko NULL bna do
    //on backtracting 0 bnana hai
    //as may be left/right dono NULL bn jaye
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
       
        root->left= pruneTree(root->left);
        root->right= pruneTree(root->right);
        
         if(root->left==NULL && root->right==NULL){
            if(root->val==0) return NULL;
            
        }
        return root;
    }
};