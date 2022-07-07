class Solution {
public:
    vector<int> parent;
    vector<vector<int>> adj;
    
    int find(int node) {
        if(parent[node]==node) return node;
        return parent[node] = find(parent[node]);
    }
    
    void join(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pv != pu) {
            parent[pu] = pv;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        adj.resize(n);
        for(auto p: pairs) {
            int u = p[0], v = p[1];
            join(u, v);
        }
        for(int i=0; i<n; i++) {
            adj[find(i)].push_back(i);
        }
        for(auto nei: adj) {
            string t = "";
            for(auto idx: nei) {
                t += s[idx];
            }
            sort(t.begin(),t.end());
            for(int i=0; i<nei.size(); i++) {
                s[nei[i]] = t[i];
            }
        }
        return s;
    }
};