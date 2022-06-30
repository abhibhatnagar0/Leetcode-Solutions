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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int depth=1;
        int ans=INT_MAX;
        dfs(root, depth, ans);
        return ans;
    }
    void dfs(TreeNode* root, int depth, int &ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            ans= min(depth,ans);
            return;
        }
        
        dfs(root->left, depth+1,ans);
        dfs(root->right,depth+1,ans);
    }
};