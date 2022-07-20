class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> dict;
        for(auto w: wordDict) dict.insert(w);
        unordered_map<string,bool> dp;
        return solve(s, dict, dp);
    }
    bool solve(string s, unordered_set<string>& dict, unordered_map<string,bool>&dp)     {
         if(s == "") return true;
        
        if(dp.find(s)!=dp.end()) return dp[s];
       
            int n = s.size();
            for(int i = 1; i<= n; ++i ){
                string t = s.substr(0, i);
                if(dict.find(t) != dict.end()){
                    if(solve(s.substr(i), dict,dp)) return dp[s]=true;
                }
            }   
        return dp[s]= false;
        }
};