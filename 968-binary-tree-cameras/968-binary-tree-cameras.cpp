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
        //want-I want a camera at my parent or childern to cover me
        //provide-I have a camera at my node. So will cover my parent and children
        //ok- I neither want or provide camera. I am either NULL or already covered
    int minCameraCover(TreeNode* root) {
            int cnt=0;
            string s= dfs(root,cnt);
            if(s=="want"){
                    cnt++;
            } 
          return cnt;  
    }
        string dfs(TreeNode* root, int &cnt){
                if(root==NULL){
                        return "ok";
                }
                string left= dfs(root->left, cnt);
                string right=dfs(root->right,cnt);
                
                if(left=="want" || right=="want"){
                  //if any child wants cam from parents, their own children did
                  //not helped them
                        cnt++;
                        return "provide";
                }
                else if(left=="provide" || right=="provide"){
                  //if any child has camera, parent wont provide or ask for it.
                        return "ok";
                }
                else{ //both left and right "ok"
                   //both childern be like- we are either NULL or got covered
                   //from our children
                   //tu tera khud dekh lawde 
                       return "want"; 
                }
        }
  //all leaf nodes will "want" (both NULL child)
  //level above leaf nodes will "provide" (child wants)
  //root will first call its sub trees by dfs, if both "ok"..root will have camera
        
};