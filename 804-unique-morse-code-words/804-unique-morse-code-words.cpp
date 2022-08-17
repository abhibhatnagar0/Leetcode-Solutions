class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        string morse[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word:words){
            string ans="";
            for(auto ch:word) ans+=morse[ch-'a'];
            st.insert(ans);
        }
        return st.size();
    }
};