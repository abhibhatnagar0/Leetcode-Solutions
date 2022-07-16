class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t= s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(t,s);
    }
     int longestCommonSubsequence(string text1, string text2) {
         int m= text1.size();
        int n= text2.size();
            vector<vector<int>> dp(2,vector<int>(n+1,0));
            
            for(int i=1;i<m+1;i++){
                  for(int j=1;j<n+1;j++){
                         if(text1[i-1]==text2[j-1])
                           dp[i&1][j]= 1+dp[(i-1)&1][j-1];
                         else dp[i&1][j]= max(dp[(i-1)&1][j],dp[i&1][j-1]);
                    }
            }
            return dp[m&1][n];
    }
};