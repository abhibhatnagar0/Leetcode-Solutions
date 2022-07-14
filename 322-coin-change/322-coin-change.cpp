class Solution {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>>&dp){
        // if amount is 0, then we need to take 0 coins to fulfill the amount
        if(amount == 0) return 0;
		// if no coins present, then we need to take infinite coins to fulfill the amount
        if(n == 0) return INT_MAX-1;
		// if already present in dp vector, we will directly return the value
        if(dp[n][amount] != -1) return dp[n][amount];
		// if the present coin is smaller than the amount, we can either take it or decide not to take it
        if(coins[n-1] <= amount){
            return dp[n][amount] = min(1 + solve(coins, amount-coins[n-1], n, dp), solve(coins, amount, n-1, dp));
        }
		// else if the coin is larger than the amount, we can't take it
        else{
            return dp[n][amount] = solve(coins, amount, n-1, dp);
        }
    }
    // unbounded knapsack
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,amount,n,dp) == (INT_MAX-1) ? -1 : solve(coins,amount,n,dp);
    }
};