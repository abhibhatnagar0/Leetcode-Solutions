class Solution {
public:
   map <string, vector<string>> dp;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set <string> word_dict(wordDict.begin(), wordDict.end());
        return helper(s, word_dict);
    }
    
    vector<string> helper(string s, set<string>& word_dict) {
    //when s.size()==0 condn addressed after
        vector<string> res;
        if (dp.find(s) != dp.end()) return dp[s];
        
        for (int i = 1; i <= s.size(); i++) {
            if (word_dict.find(s.substr(0, i)) != word_dict.end()) {
                if (s.substr(i).length() == 0) {  //here
                    res.push_back(s.substr(0, i));
                }
                else {
                    vector<string> subList = helper(s.substr(i), word_dict);
                    for (auto sub : subList) res.push_back(s.substr(0, i) + " " + sub);
                }
            }
        }
        return dp[s] = res;
    }
};