class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s= strs.size();
        vector<vector<vector<int>>>dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int i=1;i<=strs.size();i++){     
            //considering strs[i-1]
            int countzeroes = count(strs[i-1].begin(),strs[i-1].end(),'0');
            int countones = strs[i-1].size()-countzeroes;
            
            for(int j=0;j<=m;j++) //j gives no of zeroes
            {
                for(int k=0;k<=n;k++) //k gives no of ones
                {
                    //two choices
                    if(j-countzeroes>=0 && k-countones>=0)
                  dp[i][j][k] = max(1+dp[i-1][j-countzeroes][k-countones], dp[i-1][j][k]);
                    else dp[i][j][k] =  dp[i-1][j][k];   
                }
            }       
        }
        return dp[s][m][n];
    }
};