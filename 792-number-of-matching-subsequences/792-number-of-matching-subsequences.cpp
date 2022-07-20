class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        int count = 0;
        
        for(auto word:words){
            mp[word]++;
        }
        
        for(auto it:mp){
            if(isSubseq(s, it.first)){
                count += it.second;
            }
        }
        
        return count;
    }
    //checks if u is a subsequence of t
    bool isSubseq(string t, string u){
        int i = t.size()-1, j = u.size()-1;
        while(j>=0 && i>=0){
            if(t[i] == u[j]){
                i--;
                j--;
            }
            else i--;   
        }
        return (j == -1);
    }
};