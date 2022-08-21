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
        vector<TreeNode*> nodes; //stores all deepest nodes
        int mlevel=0;//level of deepest nodes
        DeepestLeaves(root,nodes,0,mlevel);
        return lca(root,nodes);
    }
    void DeepestLeaves(TreeNode* root,vector<TreeNode*>&nodes,int clevel,int &mlevel ){
        if(root->left==NULL && root->right==NULL){ //a leaf node
            if(nodes.size()==0) {
                nodes.push_back(root);
                mlevel=clevel;
            }
            else{
                if(clevel>mlevel){
                    nodes.erase(nodes.begin(),nodes.end());
                    mlevel=clevel;
                    nodes.push_back(root);
                }
                else if(clevel==mlevel) {
                    nodes.push_back(root); }
            }
            return;
        }
        if(root->left) DeepestLeaves(root->left,nodes,clevel+1,mlevel);
        if(root->right) DeepestLeaves(root->right,nodes,clevel+1,mlevel);
    }
    TreeNode* lca(TreeNode* root,vector<TreeNode*> nodes){
        if(root==NULL) return root;
        for(auto it: nodes){
            if(root==it) return root;
        }
        TreeNode* left=lca(root->left,nodes);
        TreeNode* right=lca(root->right,nodes);
        if(right==NULL) return left;
        else if(left==NULL) return right;
        else return root;
    }
};