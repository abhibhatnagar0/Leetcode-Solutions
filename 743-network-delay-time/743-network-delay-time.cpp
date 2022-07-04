const int INF = 1E9+10;
class Solution {
public:
    int dijkstra(int source, int n, vector <pair<int, int>> adj[]) {
        vector <int> vis(n+1, 0);
        vector <int> dist(n+1, INF); // vertex is the first element and weight is the second

        set <pair<int, int>> st; // wt is the first element and vertex is the second

        st.insert({0, source});
        dist[source] = 0;

        while(st.size()>0) {
            auto p = *st.begin();
            int v = p.second;
            int v_dist = p.first;
            st.erase(st.begin());
            if(vis[v]) continue;
            vis[v] = 1;
            for(auto child : adj[v]) {
                int child_v = child.first;
                int wt = child.second;
                if(dist[v] + wt < dist[child_v]) {
                    dist[child_v] = dist[v] + wt;
                    st.insert({dist[child_v],child_v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <pair<int, int>> adj[n+1];
        for(auto vec : times) {
            adj[vec[0]].push_back({vec[1],vec[2]}); // edge from vec[0] to vec[1] and vec[2] is the weight
        }
        return dijkstra(k, n, adj);
    }

};