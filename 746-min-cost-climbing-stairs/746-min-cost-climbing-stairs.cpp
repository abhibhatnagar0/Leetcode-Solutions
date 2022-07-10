class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size(); //destination
        vector<int>dp(n+1,0);
        if(n==0 || n==1) return 0;
        //dp[i] stores i tk pahuchne ke liye cost required
        dp[0]=0;
        dp[1]=0; //we can start from 0 or 1
        for(int i=2;i<=n;i++){
            dp[i] = min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};