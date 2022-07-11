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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
            if(root==NULL)return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){ // each iteration me naya level aayega
                    
                    int size=q.size();
                    while(size>0){    //for each node in that level
                            TreeNode* node=q.front();
                            q.pop();
                              if(size==1) ans.push_back(node->val);
                            if (node->left!=NULL) q.push(node->left);
                            if (node->right!=NULL) q.push(node->right);
                            size--; 
                    }   
            }
            return ans;
    }
};