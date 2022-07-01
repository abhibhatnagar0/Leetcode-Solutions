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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        
        dfs(root,0);
        return sum;
    }
    void dfs(TreeNode* root, int temp){
        if(root==NULL) return;
        temp= temp*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=temp;
            return;
        }
        dfs(root->left, temp);
      

        dfs(root->right, temp);
        

        return;
    }
};