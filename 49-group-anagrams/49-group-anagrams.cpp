class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n= strs.size();
           vector<vector<string>> ans;
            
            map <map<char,int>,vector<string>> mp;
            
            
            for(auto s:strs){
                    map<char,int> fmp;
                    for(char c:s){
                            fmp[c]++;
                    }
                    mp[fmp].push_back(s);        
            }
            
            for(auto p:mp){
                    ans.push_back(p.second);
            }
            return ans;
    }
};