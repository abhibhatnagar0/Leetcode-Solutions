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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        unordered_map<TreeNode*,TreeNode*> mp;
        findParent(root,mp);
        
        queue<TreeNode*> q;
        int dist=0;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr= q.front();
                q.pop();
                
                if(dist==k) ans.push_back(curr->val);
                
                if(curr->left!=NULL && visited.find(curr->left)==visited.end()){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right!=NULL && visited.find(curr->right)==visited.end()){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(mp.find(curr)!=mp.end() && visited.find(mp[curr])==visited.end())                  {
                    q.push(mp[curr]);
                    visited.insert(mp[curr]);
                 }
            } 
            dist++;
            if(dist>k) break;
        }

        return ans;
    }
    void findParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp){
        if(root==NULL) return;
        queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				TreeNode* node = q.front();
				q.pop();
				if (node->left) {
					mp[node->left] = node;
					q.push(node->left);
				}
				if (node->right) {
					mp[node->right] = node;
					q.push(node->right);
				}
			}
        }
    }
};