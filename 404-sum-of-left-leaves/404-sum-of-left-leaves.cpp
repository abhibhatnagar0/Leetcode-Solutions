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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
       if(root==NULL) return 0;
        bool leftChild=false;
        helper(root,leftChild);
       return sum;
    }
    void helper(TreeNode* root, bool leftChild){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(leftChild==true) {
                sum+=root->val;
                return;
            }
            else return;
        }
        helper(root->left, true);
        helper(root->right, false);
    }
};