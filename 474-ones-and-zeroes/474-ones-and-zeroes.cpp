class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s= strs.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int i=1;i<=s;i++){     
            //considering strs[i-1]
            int countzeroes = count(strs[i-1].begin(),strs[i-1].end(),'0');
            int countones = strs[i-1].size()-countzeroes;
            
            for(int j=0;j<=m;j++) //j gives no of zeroes
            {
                for(int k=0;k<=n;k++) //k gives no of ones
                {
                    //two choices
                    if(j-countzeroes>=0 && k-countones>=0)
                  dp[i%2][j][k] = max(1+dp[((i-1)%2)][j-countzeroes][k-countones], dp[(i-1)%2][j][k]);
                    else dp[i%2][j][k] =  dp[(i-1)%2][j][k];   
                }
            }       
        }
        return dp[s%2][m][n];
    }
};