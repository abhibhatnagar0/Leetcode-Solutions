class Solution {
public:
     bool dfs(vector<vector<int>>& graph,vector<int>& color,int node, vector<bool> &hasCycle)
    {
        color[node]=1;  // Initially assume that the node is unsafe.
        
        for(auto cur : graph[node])
            if((color[cur]==0 && dfs(graph,color,cur,hasCycle)) || color[cur]==1){
                hasCycle[node] =true;
                return true;
            }
        
        color[node]=2;  // If there is no cycle mark node as safe.
        hasCycle[node]=false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0) ,result;
		vector<bool> hasCycle(n,false);
		// If node is visited and safe or unvisited and does not contain cycle then add it to the answer.
        
         for(int i=0;i<graph.size();i++){
             if(color[i]==0) dfs(graph,color,i,hasCycle);
         }
            
        
        for(int i=0;i<graph.size();i++){
            if(color[i]==2 || hasCycle[i]==false)
                result.push_back(i);
        }
                
        return result;
    }
};