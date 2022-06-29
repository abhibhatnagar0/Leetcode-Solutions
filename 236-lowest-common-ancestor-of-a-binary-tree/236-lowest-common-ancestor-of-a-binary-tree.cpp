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
         //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        //first try of finding lca only in left or righr subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right; //both p and q in right subtree
        }
        else if(right == NULL) {
            return left;  //both p and q in left subtree
        }
        else { 
     //both left and right are not null, both have one of p or q respectively
            return root;
        }
    }
//that node jiske left se p/q, right se q/p return hoga..will be lca
//if at a node,left side returns a node, and right is null, ie p,q both lies in left
};