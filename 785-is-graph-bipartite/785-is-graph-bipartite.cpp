class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v= graph.size();
            vector<int> color(v,0);
            //color[i]=0 means ith node of graph is unvisited
            
            for(int i=0;i<v;i++){
                    if(color[i]==0){ //for every unvisited node
                       color[i]=1; //giving it a color
                        if(dfs(i,graph,color)==false) return false;
                    }
            }
            return true;
    }
        bool dfs(int vertex,vector<vector<int>>& graph, vector<int>& color){
                vector<int> neighbours = graph[vertex];
                for(int neighbour: neighbours){
                        if(color[neighbour]==0){
                                color[neighbour]= (color[vertex]==1)?2:1 ; //giving neighbour different color
                                if(dfs(neighbour,graph,color)==false) return false;
                        }
                        else if(color[neighbour]==color[vertex]){
                                return false;
                        }
                        else{
                                //neighbour has different color than that of mine
                                continue;
                        }
                }
                return true;       
        }
};