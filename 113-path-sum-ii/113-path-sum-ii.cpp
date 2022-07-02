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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        if(root==NULL) return paths;
        long long sum=0;
        vector<int> path;
        helper(root,sum,path,paths,targetSum);
        return paths;
    }
    void helper(TreeNode* root, long long sum, vector<int>path, vector<vector<int>>& paths, int targetSum){
        if(root==NULL) return;
        
        path.push_back(root->val);
        sum+=root->val;
        if(sum>INT_MAX) return;
        
        if(root->left==NULL && root->right==NULL){
           if(sum==targetSum){
               paths.push_back(path);
               return;
           } 
        }
        
        helper(root->left,sum,path,paths,targetSum);
        helper(root->right,sum,path,paths,targetSum);
           
    }
};