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
    int maxdiff=INT_MIN;
    
    int maxAncestorDiff(TreeNode* root) {
        helper(root);
        return maxdiff; //max-min
    }
    pair<int,int> helper(TreeNode* root){
        if(root==NULL) return {INT_MIN,INT_MAX};
        if(root->left==NULL && root->right==NULL){
            return {root->val, root->val};
        }
        pair<int,int> left= helper(root->left);
        pair<int,int> right= helper(root->right);
        
        int minOfchildren= min(left.second,right.second);
        int maxOfchildren= max(left.first,right.first);
        //roots val can lie anywhere
        //its abs diff with a child node can be maximum if we take extreme values
        //of children
        int diff= max(abs(root->val-minOfchildren), abs(root->val-maxOfchildren));
        maxdiff= max(diff,maxdiff);
        
        return {max(root->val,maxOfchildren),min(root->val,minOfchildren)};
        
    }
};