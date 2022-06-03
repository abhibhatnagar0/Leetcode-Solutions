class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n= strs.size();
           vector<vector<string>> ans;
            // all anagrams have same sorted order
            unordered_map<string,vector<string>> mp;
            //{sorted order of str, all anagram strings}
            
            for(auto s:strs){
                    string temp=s;
                    sort(temp.begin(),temp.end());
                    mp[temp].push_back(s);
            }
            
            for(auto p:mp){
                    ans.push_back(p.second);
            }
            return ans;
    }
};