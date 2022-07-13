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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
            if(root==NULL)return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){ // each iteration me naya level aayega
                    vector<int> level;
                    int size=q.size();
                    while(size>0){    //for each node in that level
                            TreeNode* node=q.front();
                            q.pop();
                            level.push_back(node->val);
                            if (node->left!=NULL) q.push(node->left);
                            if (node->right!=NULL) q.push(node->right);
                            size--; 
                    }
                    ans.push_back(level);     
            }
            return ans;
    }
};