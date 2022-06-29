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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxWidth=INT_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size= q.size();
            int s = q.front().second;
            int e = q.back().second;
            maxWidth = max(maxWidth, e - s + 1);
           
            for(int i=0;i<size;i++){
                 pair<TreeNode*, int> p= q.front();
                 q.pop();
                int idx= p.second - s;
                if(p.first->left !=NULL){
                    q.push({p.first->left, (long long)2*idx});
                }
                if(p.first->right !=NULL){
                    q.push({p.first->right, (long long)2*idx+1});
                }  
            }
        }
        return maxWidth;
    }
};