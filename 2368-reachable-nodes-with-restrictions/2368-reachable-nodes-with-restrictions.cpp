class Solution {
public:
            int cnt=0;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        sort(restricted.begin(),restricted.end());
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        for(auto x: restricted){
            vis[x]=1;
        }
       dfs(0,adj,vis,restricted);
        
        return cnt;
        
    }
    void dfs(int node, vector<vector<int>> &adj, vector<int>&vis,vector<int>& restricted){
        if(vis[node]==1) return;
        vis[node]=1;
        cnt++;
        
        for(auto nei: adj[node]){
            if(vis[nei]==0){
                dfs(nei,adj,vis,restricted);
            }
        }
        return;
    }
    
};