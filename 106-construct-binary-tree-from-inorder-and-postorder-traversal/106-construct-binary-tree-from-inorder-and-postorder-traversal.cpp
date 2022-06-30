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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
     for(int i=0;i<inorder.size();i++) in.insert({inorder[i],i}); //inserting elements of inorder to map
        
        return construct( postorder, inorder, 0, inorder.size()-1, postorder.size()-1);
    }
    //Below is a recursive function for building the tree, i is the starting index of inorder and j is the ending index of inorder. preIndex is the index of element in postorder
    TreeNode* construct(vector<int>& postorder, vector<int>& inorder,int i, int j,int postIndex){
        if(i>j) return NULL; //if start>end
        
        TreeNode* root= new TreeNode(postorder[postIndex]); //we create a root node and insert postorder element to it
        int inIndex=in[postorder[postIndex]]; //We find that element in inorder through map and store its index
        
        root->left=construct(postorder,inorder,i,inIndex-1, postIndex-1-(j-inIndex)); //constructing the left subtree
        root->right=construct(postorder,inorder,inIndex+1,j,postIndex-1); //constructing the right subtree
        return root;
    }
    //for left subTree, postIndex is 
    // (postIndex of full tree)-1 - (len of right subTree)
    // postIndex-1 - (j-inIndex)
};