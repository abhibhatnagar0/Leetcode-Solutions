class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int find(int u)
        {
            if(u == par[u]) return u;
            return par[u] = find(par[u]);
        }
    void unionByRank(int u, int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(rank[u]>rank[v]) par[v]=u;
        else if(rank[u]<rank[v])par[u]=v;
        else{
            par[v]=u;
            rank[u]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1) unionByRank(i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(par[i]==i) cnt++;
        }
        return cnt;
    }
};