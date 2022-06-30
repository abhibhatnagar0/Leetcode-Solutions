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
    unordered_map<int,int> in; //We've to traverse inorder for every index of preorder,so to reduce the time we store the elements of inorder into map
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     for(int i=0;i<inorder.size();i++) in.insert({inorder[i],i}); //inserting elements of inorder to map
        
        return construct( preorder, inorder, 0, inorder.size()-1,0);
    }
    //Below is a recursive function for building the tree, i is the starting index of inorder and j is the ending index of inorder. preIndex is the index of element in preorder
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder,int i, int j,int preIndex){
        if(i>j) return NULL; //if start>end
        
        TreeNode* root= new TreeNode(preorder[preIndex]); //we create a root node and insert preorder element to it
        int inIndex=in[preorder[preIndex]]; //We find that element in inorder through map and store its index
        
        root->left=construct(preorder,inorder,i,inIndex-1,preIndex+1); //constructing the left subtree
        root->right=construct(preorder,inorder,inIndex+1,j,preIndex+ inIndex-i+1); //constructing the right subtree
         
        return root;
    }
};
    //finding preIndex in right subtree
    // (preIndex of full tree)+ (len of left subTree) + 1......ie starting ele of right subTree
    // (preIndex)             + (inIndex-i)           + 1
    