class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+1,10010);
        dp[0]=0;
        
        for(int j=0;j<coins.size();j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(i-coins[j]>=0)
                {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[n]>10000?-1:dp[n];
    }
};