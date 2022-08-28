class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
         unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        //for each diff, stores all elements in that diagonal with min at top
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push(mat[i][j]);
            }
        }
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return ans;
    }
};