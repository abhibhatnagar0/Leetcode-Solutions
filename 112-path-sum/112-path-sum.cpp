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
    int pathSum=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        
        pathSum+= root->val;
        
        if(root->left==NULL && root->right==NULL){
            if(pathSum==targetSum) return true;
        }
        
        bool a= hasPathSum(root->left, targetSum);
        bool b= hasPathSum(root->right, targetSum);
            
        pathSum-=root->val;
        
        if(a||b) return true;
        else return false;

    }
};