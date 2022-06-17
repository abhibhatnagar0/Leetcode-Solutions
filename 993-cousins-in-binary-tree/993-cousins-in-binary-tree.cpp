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
    bool isCousins(TreeNode* root, int x, int y) {
         
            if(root->val==x || root->val==y)return false;
            queue<TreeNode*> q;
            q.push(root);
            bool flag= false;
            //flag will become true when x ka parent milega
            
            while(!q.empty() && flag==false){ 
                    
                    int size=q.size();
                    for(int i=0;i<size;i++){    
                            TreeNode* node=q.front();
                            q.pop();
                            if(node->left!=NULL && node->left->val==x || node->right!=NULL && node->right->val==x){
                                    //node is x ka parent
                                    //wont push its children in queue
                                    flag = true;
                            }
                            else{
                            if (node->left!=NULL) q.push(node->left);
                            if (node->right!=NULL) q.push(node->right);
                            }       
                    }       
            }
            if(flag==false) return false; //couldnt find a node with x as child
            else if(flag==true && !q.empty()){ //all nodes in q are cousins of x
                                             //as they have same lvl and diff parent
                    while(!q.empty()){
                            TreeNode* node=q.front();
                            q.pop();
                            if(node->val==y) return true;
                    }   
            }
             return false;
            
            
    }
};