class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int m= numCourses;
         
        vector<vector<int>> adj(m);
        vector<int> indegree(m,0);
        
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        vector<bool> visited(m,false);
        queue<int> q;
       
        for(int i=0;i<m;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i]=true;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour :adj[node]){
                if(visited[neighbour]==0){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
            }
        }
        
    if(ans.size() == m){
        return ans;
    }
    else{
        ans.clear();
        return ans;
    }
        
    }
};