class Solution {
public:
    int removePalindromeSub(string s) {
            int n=s.size();
        if(n==0) return 0;
        else if(isPalindrome(s,0,n-1)) return 1;
         else return 2; //remove all a and then b
    }
        bool isPalindrome(string s, int i, int j){
                if(i>=j) return true;
                
                if(s[i]==s[j]){
                        if(isPalindrome(s,i+1,j-1)) return true;
                }
                return false;
               
        
        }
};