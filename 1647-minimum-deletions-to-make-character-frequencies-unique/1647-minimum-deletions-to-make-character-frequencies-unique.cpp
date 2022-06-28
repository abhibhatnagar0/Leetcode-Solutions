class Solution {
public:
    int minDeletions(string s) {
        int n= s.size();
        unordered_map<char,int> mp;// stores freq
        for(char c: s){
            mp[c]++;
        }
        
        unordered_set<int> st; //stores unique freqs so far
        int deletions=0;
        
        for(auto p: mp){
            if(st.find(p.second)==st.end()){
                //this freq is coming 1st time
                st.insert(p.second);
            }
            else{
                //this freq had appeared before
                p.second--;
                deletions++;
                while(p.second!=0 && st.find(p.second)!=st.end()){
                     p.second--;
                     deletions++;
                }
                if(p.second ==0) continue;
                else{
                    st.insert(p.second);
                }    
            }
        }
        return deletions;
    }
};