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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
        return ans;
        
        queue<pair<TreeNode*,int>>qu;
        qu.push({root,0});
        int row=0;
        map<int,vector<pair<int,int>>> m;
		
		//bfs traversal
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--){
                TreeNode* temp = qu.front().first;
                int col = qu.front().second;
                qu.pop();
                m[col].push_back({temp->val,row});
                if(temp->left)
                qu.push({temp->left,col-1});
                if(temp->right)
                qu.push({temp->right,col+1});
            }
            row++; 
        }
        
		
		//putting values in vector
        vector<pair<int,int>> v;
        for(auto it=m.begin();it!=m.end();it++){
            v=it->second;
            sort(v.begin(),v.end(),cmp);

            vector<int> v1;
            for(auto i:v){
                v1.push_back(i.first);

            }
            ans.push_back(v1);
            v1.clear();  
        }
        return ans;
    }
    bool static cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second)
                   return a.first<b.first;
               else 
                   return a.second<b.second;
    }
};