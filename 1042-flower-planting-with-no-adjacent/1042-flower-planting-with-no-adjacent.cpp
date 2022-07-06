class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
    for(auto p: paths)
    {
        int u = p[0];
        int v = p[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> color(n+1,0);
    for(int i =1;i<=n;i++) //bfs on all unvisited nodes
    {
        if(color[i]==0)
        {
            queue<int> q;
            q.push(i);
            color[i]=1; //by default,giving 1 color to starting node of a connection
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto it: adj[node])
                {
                    if(color[it]==0 || color[it]==color[node])
                    {
                        color[it]=color[node]+1;
                        q.push(it);
                    }
                    if(color[it]>4) color[it] = color[it]%4;
                }
            }
        }
    }
    color.erase(color.begin());
    return color;
    }
};