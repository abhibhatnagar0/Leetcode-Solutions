class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();// destination
        vector<int> dp(n+1,-1);
            int op1= helper(0,n,cost,dp);
            int op2= helper(1,n,cost,dp);
        return min(op1,op2);
    }
    int helper(int i,int n, vector<int>& cost, vector<int> &dp){
        if(i==n) return 0;
        if(i>n) return 10000; //INF
        if(dp[i]!=-1) return dp[i];
        return dp[i]= min(helper(i+1,n,cost,dp)+ cost[i], helper(i+2,n,cost,dp) + cost[i]);
    }
};