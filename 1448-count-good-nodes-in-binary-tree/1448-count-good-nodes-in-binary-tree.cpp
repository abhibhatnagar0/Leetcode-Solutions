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
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int maxSofar=root->val;
        dfs(root,cnt,maxSofar);
        return cnt;
    }
    void dfs(TreeNode* root, int &cnt, int maxSofar){
        if(root==NULL) return;
        if(root->val >=maxSofar){
            cnt++;
            maxSofar= root->val;
        }
        
        dfs(root->left,cnt,maxSofar);
        dfs(root->right,cnt,maxSofar);
        
    }
};