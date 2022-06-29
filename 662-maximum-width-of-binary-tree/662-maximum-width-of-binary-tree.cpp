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
    /* width of BT is mox no of nodes that can come in btw 2 extreme nodes at a lvl.
    we are giving idx to each node at each level...such that first node of each lvl
    has 0 idx.
    for this, we marked root as i=0 and its children as 2*i and 2*i+1.
    This gives   0
              0      1
            0   1   2   3
           0 1 2 3 4 5 6 7 
        but this wont start from 0 if leftmost node is not there
        which can cause overflow as after 31 levels, idxs of nodes will overflow.
        a level can have start= 33.....end=69...width of this lvl= 69-33+1
        we will make start=0 always and end idx= p.second-start
        SO 
          for next level idxs will be 2*idx and 2*idx+1.
    
    */
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxWidth=INT_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size= q.size(); //curr level ka size
            int s = q.front().second; //curr level ka smallest existing index
            int e = q.back().second;  //curr level la largest existing index
            maxWidth = max(maxWidth, e - s + 1);
           
         for(int i=0;i<size;i++){//adding children of all nodes of curr lvl in queue
             
                 pair<TreeNode*, int> p= q.front();
                 q.pop();
                int idx= p.second - s; //to make curr lvl start from 0
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