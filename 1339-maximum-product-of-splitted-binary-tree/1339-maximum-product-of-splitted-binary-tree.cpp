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
    
     long res = 0, sum=0,total=0;
    bool flag=false;
    
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        flag=true;
         dfs(root);
        return (int)(res % (int)(1e9 + 7));
    }

    int dfs(TreeNode* root) {
        if (root==NULL) return 0;
        int left= dfs(root->left);
        int right= dfs(root->right);
        sum = root->val + left + right;
        if (flag==true)
        res = max(res, sum * (total - sum));
        return sum;
    }
    /*dfs(node) will return sum of subTree upto node
    dfs(root) will return total sum of tree, tb tk res statement wont execute
    as tb tk total was 0.
    Once we know total, call dfs(root) to update res for all possible nodes(with
    cuts at their above edges)
    
       on calling dfs(node), we also calculate updated value of res
       if cutting edge above node, can give a increased value of res
       */
};