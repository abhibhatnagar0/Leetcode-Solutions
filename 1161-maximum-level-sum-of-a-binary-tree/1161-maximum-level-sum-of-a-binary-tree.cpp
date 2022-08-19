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
    int maxLevelSum(TreeNode* root) {
         if(root==NULL) return 0;
        int maxsum=INT_MIN, maxsumlevel=1,level=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int csum=0;
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                csum+=root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(csum>maxsum){
                maxsum=csum;
                maxsumlevel=level;
            }
            level++;
        }
        return maxsumlevel;
    }
};