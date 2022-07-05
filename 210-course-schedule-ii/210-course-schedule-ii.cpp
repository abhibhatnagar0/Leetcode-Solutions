class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n= numCourses;
        vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    
    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        
        adj[v].push_back(u);
        indegree[u]++;
    }
    
    vector<int> ans;
    bfs(adj, indegree, ans);
    
    if(ans.size() == n){
        return ans;
    }
    else{
        ans.clear();
        return ans;
      }
    }
    
    void bfs(vector<vector<int>> &adj, vector<int> &indegree, vector<int> &ans){
    queue<int> q;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
    }
}
};