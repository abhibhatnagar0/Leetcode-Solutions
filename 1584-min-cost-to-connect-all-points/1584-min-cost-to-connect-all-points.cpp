class Solution {
public:
        
     static int findParent(int u, vector<int> &parent, vector<int> &rank){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findParent(parent[u], parent, rank);
    }
    static void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[u]>rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        vector<vector<int>> edges;
        
        for(int i=0; i<n-1; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dist = abs(x2-x1)+abs(y2-y1);
                
                edges.push_back({dist,i, j});
            }
        }
        //initially all points(nodes) are separated
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        sort(edges.begin(), edges.end());
        
        int cost = 0;
        int vertices= n-1;
        for(int i=0; i<edges.size(); i++){
          if(vertices==0) break;
            
            int u = edges[i][1];
            int v = edges[i][2];
            int w = edges[i][0];
            
            int pu = findParent(u, parent, rank);
            int pv = findParent(v, parent, rank);
            
            if(pu!=pv){
                unionByRank(pu, pv, parent, rank);
                cost+=w;
                vertices--;
            }
        }
        
        return cost;
    }
};