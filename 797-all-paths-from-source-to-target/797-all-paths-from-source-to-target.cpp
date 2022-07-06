class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
              int n=graph.size();
            vector<vector<int>> allpaths;
            vector<int> path;
            dfs(graph,allpaths,path,0);
            return allpaths;
    }
    void dfs(vector<vector<int>> graph, vector<vector<int>> &allpaths,vector<int>path,int node){
           path.push_back(node);
            if(node==graph.size()-1){
                    allpaths.push_back(path);
            }
            else{
                    for(auto child: graph[node]){
                            dfs(graph,allpaths,path,child);
                    }
            }
            
    }    
};