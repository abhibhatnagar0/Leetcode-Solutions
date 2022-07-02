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
    int deepestLeavesSum(TreeNode* root) {
        if (root==NULL) return 0;
        int lvl=0;
        int maxlvl=0; //leaf nodes ka max level
        int sum=0;
        helper(root,lvl,maxlvl,sum);  
        return sum;
    }
    void helper(TreeNode* root, int lvl, int &maxlvl, int &sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(lvl>maxlvl){
                maxlvl=lvl;
                sum=0;
                sum+=root->val;
            }
            else if(lvl==maxlvl){
                sum+=root->val;
            }
        }
        helper(root->left,lvl+1,maxlvl, sum);
        helper(root->right,lvl+1,maxlvl,sum);
    }
};