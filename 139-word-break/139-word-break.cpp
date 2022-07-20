class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> dict;
        for(auto w: wordDict) dict.insert(w);
        
         int n = s.size();
        
        vector<bool> dp(n+1, false);
        //dp[i] stores true if prefix substring of s of length i can be
        //segmented
        dp[0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j]==true)
                {
                    string str = s.substr(j, i-j); //remaining substr
                    if(dict.find(str)!= dict.end())
                    {
                        dp[i] = true;
                        break; //move out of j loop
                    }
                }
            }
        }     
        return dp[n];
    }
};