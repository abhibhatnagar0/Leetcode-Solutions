class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
            string s=to_string(x);
            int n=s.size();
            int i=0,j=n-1;
            return helper(s,0,n-1);
    }
        bool helper(string s,int i, int j){
                if(i>=j) return true;
                if(s[i]!=s[j]) return false;
                else return helper(s,i+1,j-1);
              
        }
};