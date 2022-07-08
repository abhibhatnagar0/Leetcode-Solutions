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
    int rob(TreeNode* root) {
        pair<int,int> ans=helper(root);
        return max(ans.first, ans.second); //{inc,exc}
    }
    
    //helper function to return the maximum sum of non-adjacent nodes.
    pair<int,int> helper(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
         pair<int,int> p;
        pair<int,int> left= helper(root->left);
        pair<int,int> right= helper(root->right);
        
        //including root
        p.first= root->val + left.second + right.second;
        //excluding root
        p.second= max(left.first,left.second) + max(right.first,right.second);
        
        return p;
    }
};