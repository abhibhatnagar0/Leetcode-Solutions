class Solution {
public:
        vector<string> ans;
    vector<string> generateParenthesis(int n) {
            
        string curr;
            helper(n,curr,0,0);
            return ans;
    }
        void helper(int n,string &curr,int open, int close){
                //open,close are no of '(' and ')' in curr string
                if(curr.size()==(n*2)) { //or if(open==close==n)
                        ans.push_back(curr);
                        return;
                }
                if(open<n){
                        curr.push_back('(');
                        helper(n,curr,open+1,close);
                        curr.pop_back();
                }
                if(close<n && close<open){
                        curr.push_back(')');
                        helper(n,curr,open,close+1);
                        curr.pop_back();
                }
                
        }
};