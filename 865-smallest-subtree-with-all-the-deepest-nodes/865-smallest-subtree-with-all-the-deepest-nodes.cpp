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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode*p=NULL, *q=NULL;
        //p,q are extreme nodes of deepest level in tree
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int n= qu.size();
            for(int i=0;i<n;i++){
                TreeNode* node= qu.front();
                qu.pop();
                if(i==0) p= node;
                if(i==n-1) q= node;
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        return lca(root,p,q);
    }
   
    TreeNode* lca(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q) return root;
        if(p==q) return p; //only one deepest node
        
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(right==NULL) return left;
        else if(left==NULL) return right;
        else return root;
    }
};