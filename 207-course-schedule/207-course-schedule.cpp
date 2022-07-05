class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m= numCourses;
        
        vector<vector<int>> adj(m);
        vector<int> indegree(m,0);
        
        for(auto v:prerequisites){
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        vector<bool> visited(m,false);
        queue<int> q;
        int count=0;
        for(int i=0;i<m;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
                visited[i]=true;
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour :adj[node]){
                if(visited[neighbour]==0){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                        count++;
                        visited[neighbour]=true;
                    }
                }
            }
        }
        
        if(count==numCourses) return true;
        else return false;
        
    }
};