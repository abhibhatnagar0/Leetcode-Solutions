class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        if(k>n) k=n;
        vector<vector<int>> dp(k+1,vector<int>(n,0)); 
        //dp[i][j] gives max profit when i transactions allowed till j index (jth day)
        //dp[0][any no]=0 ....no transactions no profit
        //dp[any no][0]=0 ....for single day no profit
        for(int i=1;i<=k;i++){
             int val= INT_MIN; // to avoid for loop from 0 to j-1
            for(int j=1;j<n;j++){  
                   val=max(val, dp[i-1][j-1] - prices[j-1]); // val gives complete k-1 transactions profit + buying price of 
                                                             // ith transaction(the one from 0 to j-1) that gives max val
                      dp[i][j] = max(dp[i][j-1], val + prices[j]);
              }             
            }
        return dp[k][n-1];
      }
};