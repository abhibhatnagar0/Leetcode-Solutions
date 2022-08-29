class Solution {
public:
    // vector<int>par;
    // vector<int>rank;
    // int find(int u)
    //     {
    //         if(u == par[u]) return u;
    //         return par[u] = find(par[u]);
    //     }
    // void unionByRank(int u, int v){
    //     u=find(u);
    //     v=find(v);
    //     if(u==v) return;
    //     if(rank[u]>rank[v]) par[v]=u;
    //     else if(rank[u]<rank[v])par[u]=v;
    //     else{
    //         par[v]=u;
    //         rank[u]++;
    //     }
    // }
  
       vector<int> visited;
    int findCircleNum(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        visited.resize(n,0);
        int cnt=0;
       for(int i=0;i<n;i++){           
           if(visited[i]==0) {
               dfs(i,isConnected);
               cnt++;
           }
       } 
        return cnt;   
    }
    
    void dfs(int s,vector<vector<int>>& isConnected){
        visited[s]=1;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==0 && isConnected[s][i]==1){
                dfs(i,isConnected);
            }
        }
    }
};