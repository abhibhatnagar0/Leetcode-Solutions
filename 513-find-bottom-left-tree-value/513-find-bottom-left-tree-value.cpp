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
    int findBottomLeftValue(TreeNode* root) {
        int ans=-1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n= q.size();
            bool flag=false; //for new level
            for(int i=0;i<n;i++){
                TreeNode* curr= q.front();
                q.pop();
                if(flag==false){ //bs ek baar execute hoga har level ki starting me
                    ans=curr->val;
                    flag=true;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);    
            }
        }
        return ans;
    }
};