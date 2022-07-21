class Solution {
public:
    int maxlen=0;
    int maxLength(vector<string>& arr) {
        int n= arr.size();
        string s="";
        unordered_set<char>st;
        helper(arr,s,0,st);
        return maxlen;
    }
    void helper(vector<string>& arr, string s, int i,unordered_set<char>&st){
        unordered_set<char>st2;
        if(i==arr.size()){
            int n=s.size();
           maxlen= max(n,maxlen); 
           return;
        }
        helper(arr,s,i+1,st);
        
        for(auto ch: arr[i]){
            if(st.find(ch)!=st.end() || st2.find(ch)!=st2.end()) return;
            st2.insert(ch);
        }
        for(auto ch: st2){
            st.insert(ch);
        }
        
        helper(arr,s+arr[i],i+1,st);
        for(auto ch: arr[i]) st.erase(ch);
    }
};