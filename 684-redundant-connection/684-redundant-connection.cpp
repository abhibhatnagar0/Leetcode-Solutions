class Solution {
public:
     vector<int>par;
    vector<int>rank;
    int find(int u)
        {
            if(u == par[u]) return u;
            return par[u] = find(par[u]);
        }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
        for(vector<int> edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            u= find(u);
            v = find(v);
            if(u!=v) //u v are from different components
            {
                if(rank[u]>rank[v]) par[v]=u;
                
                else if(rank[v]>rank[u]) par[u]=v;
                
                else
                {
                    par[u]=v;
                    rank[v]++;
                }
            }
            else
            {
                return edge; //edge jisse cycle create ho jati is to be removed
            }
        }
        return {}; //no cycle found
    }
};