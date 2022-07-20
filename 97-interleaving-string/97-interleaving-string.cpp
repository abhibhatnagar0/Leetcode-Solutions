class Solution {
public:
    bool dp[110][110]={false};
    bool isInterleave(string s1, string s2, string s3) {
        int m= s1.size();
            int n= s2.size();
            if(m+n!=s3.size())
                    return false;
        for(int i=0; i<=m; ++i){
                for(int j=0; j<=n; ++j){
                        if(i==0 && j==0){
                                dp[i][j]=true;
                        }
                        else if(i==0) // s1 is empty
                                dp[i][j]= s2[j-1]==s3[i+j-1]? dp[i][j-1]:false;
                        else if(j==0) // s2 is empty
                                dp[i][j]= s1[i-1]==s3[i+j-1]? dp[i-1][j]:false;
                        else
                            dp[i][j]= (s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);      
                }
            }
        return dp[m][n];
    }
};