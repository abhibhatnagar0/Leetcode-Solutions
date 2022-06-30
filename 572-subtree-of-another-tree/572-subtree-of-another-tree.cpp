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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            if(subRoot!=NULL) return false;
            else return true;
        }
        else{
            if(subRoot==NULL) return true;
        }
        if(sameTree(root,subRoot)) return true;
        if( isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) ){
            return true;
        }
        else return false;
    }
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(root==NULL){
            if(subRoot!=NULL) return false;
            else return true;
        }
        else{
            if(subRoot==NULL) return false;
        }
        
        if(root->val==subRoot->val && sameTree(root->left,subRoot->left) && sameTree(root->right,subRoot->right)){
            return true;
        }
        else return false;
    }
};