class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> color(n+1, 0);
        
        for(int i=1;i<=n;i++){ //dfs on all unvisted nodes
            if(color[i]==0){
                dfs(i, color, adj);
            //dfs(node) first finds feasible color of the node
            //then calls dfs on its unvisted neighbours
            }
        }
        color.erase(color.begin()); //color[0] will be 0 always
        return color;               //as nodes are from 1 to n
    }
    void dfs(int v, vector<int> &color, vector<int> adj[]){
        for(int i=1;i<=4;i++){ //i represents color 1,2,3,4
            bool possible=true;
      //possible tells if its possible for node v to have color i      
            for(auto x: adj[v]){
                if(color[x]==i){
                    possible =false;
                    break;
                }
            }
            if(possible==true){
                color[v]=i;
                break;
            }
        }
        for(auto x: adj[v]){
            if(color[x]==0)
               dfs(x, color, adj);
        }
    }
};