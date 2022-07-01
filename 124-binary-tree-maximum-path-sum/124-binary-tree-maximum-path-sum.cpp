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
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root, maxSum);//helper(root) returns sum of a single path having root
        return maxSum;
    }
    int helper(TreeNode* root, int& maxSum){
        if(root==NULL) return 0;
        
        int left= helper(root->left, maxSum);
        if(left<0) left=0;
        //left is max single path sum of left subTree
        int right= helper(root->right, maxSum);
        if(right<0) right=0;
        //right is max single path sum of right subTree

        //helper(root) checks sum of if its curved path (root+left+right)
        //and updates maxSum if it can.
        //if left or right gives neg sum, root wont take them. hence they are made 0
       
        maxSum= max(maxSum, left+right+ root->val);
        
        //whatever returned by helper(root) will be used by its parent as left/right 
        return root->val + max(left,right); //single path
    }
    
};