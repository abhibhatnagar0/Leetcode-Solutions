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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return -1;
            int x1=diameterOfBinaryTree(root->left);
            int x2=diameterOfBinaryTree(root->right);
            int x3= height(root->left)+height(root->right)+2;
            return max(max(x1,x2),x3);
            
    }
    //here height corresponds to the no of edges in btw 
    int height(TreeNode* root){
            if(root==NULL) return -1; 
         //0 node= height -1
         //1 node= height  0
        
            int lefth=height(root->left);
            int righth=height(root->right);
            return max(lefth,righth)+1;
    }    
        
};