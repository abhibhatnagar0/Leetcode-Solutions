class Solution {
public:
    vector<string> ans;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string temp = ""; //for storing temp ans of string s
        
        unordered_set<string> dict;
        for(auto w: wordDict) dict.insert(w);
        
        solve(s, dict, temp);
        return ans;
    }
    void solve(string s, unordered_set<string>& dict, string temp ){
        if(s == ""){
            ans.push_back(temp);
        }else{
            int n = s.size();
            for(int i = 1; i<= n; ++i ){
                string t = s.substr(0, i);
                if(dict.find(t) != dict.end()){
                    solve(s.substr(i), dict, temp + (temp == ""? t : (" " + t)));
                }
            }   
        }
    }
};