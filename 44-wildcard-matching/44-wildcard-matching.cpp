class Solution {
public:
    bool isMatch(string s, string p) {
        int m= s.size();
        int n= p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        //dp[i][j] stores string s of size i, p of size j
        //it gives true if insertions of patterns in p make it = s
         dp[0][0]=true; 
        //filling 1st row i=0
        for (int j=1;j<=n;j++) { //when s is empty 
            //if j has ? or some char, it or any future j can nvr match with empty s string
            if(p[j-1]!='*') break; //if j has *, it can be relaced with ""
            else dp[0][j]=true;  //hence can give true
        }
        //in 1st col when p is empty nd s have any char, ans always false
       
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                
                if (s[i-1]==p[j-1]||p[j-1]=='?') dp[i][j]=dp[i-1][j-1]; //when p[j-1]=='?' it can be = s[i-1]
                
                else if (p[j-1]=='*') dp[i][j]=dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1];
                      //  * can be replaced with (s[i-1]   , ......s[i-1] ,    ""  )
                
                else dp[i][j]=false;
            }
        }
        return dp[m][n];
    }
};