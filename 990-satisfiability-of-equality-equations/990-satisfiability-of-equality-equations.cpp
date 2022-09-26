class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int find(int u)
        {
            if(u == par[u]) return u;
            return par[u] = find(par[u]);
        }
    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++) par[i]=i;
        
        for(auto s: equations){
          if(s[1]=='='){
              if(s[0]==s[3]) continue;
               int u = find(s[0]-'a');
               int v = find(s[3]-'a');
                if(u==v) continue; 
                if(rank[u]>rank[v]) par[v]=u;
                else if(rank[u]<rank[v])par[u]=v;
                else{
                  par[v]=u;
                  rank[u]++;
                }
            }
        }
        for(auto s: equations){
            int u = find(s[0]-'a');
            int v = find(s[3]-'a');
            if(s[1]=='!'){
                if(u==v) return false;
                else continue;
            }
         }
        return true;
    }
};