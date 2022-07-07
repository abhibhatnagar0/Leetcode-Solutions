class Solution {
public:
    //keep removing leaf nodes until we are left with only 2 or 1 node.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; //0 is only node
        if(n==2) return {0,1}; //any of 2 nodes can be root with depth 1
         vector<vector<int>> graph(n);
        vector<int> degree(n, 0); //vector<int> indegree keeps count of the number of nodes connected to a node
        
        for(auto e : edges){   //Creating an adjacency matrix for the given graph
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n;i++){
            if(degree[i]==1) q.push(i); //add all the leaf nodes to the queue
        
        } 
        
        while(n>2){
            int s = q.size();
            n-=s; //removing leaf nodes
            for(int i=0; i<s;i++){
                int curr = q.front();
                q.pop();
                for(auto child : graph[curr]){ //For each node, attached to the leaf niodes, we decrement the degree i.e remove the leaf nodes connected to them. We keep on doing this until we reach the middle nodes.
                    degree[child]--;
                    if(degree[child]==1) q.push(child);   
                }
            }
        }
      vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};