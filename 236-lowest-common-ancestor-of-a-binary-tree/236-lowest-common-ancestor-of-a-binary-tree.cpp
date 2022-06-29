/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
         TreeNode* ans;
         int idx1 = 0, idx2 = 0;
        if(getPath(root,p,path1) && getPath(root,q,path2)){
             int size1 = path1.size();
             int size2 = path2.size();
        
        while (idx1 < size1 && idx2 < size2) {
            if (path1[idx1] == path2[idx2]) {
                idx1++;
                idx2++;
                continue;
            }
            else break;
        }
            idx1--;
        }
           return path1[idx1];   
              
    }
    bool getPath(TreeNode* root, TreeNode*p, vector<TreeNode*> &path){
        if(root==NULL) return false;
        
           path.push_back(root);
        if(root==p){
            return true;
        }
        
          if(getPath(root->left,p,path) || getPath(root->right,p,path)){
              return true;
          }
           path.pop_back();
        
         return false;
    }
};