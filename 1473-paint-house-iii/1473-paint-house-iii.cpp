class Solution {
public:
     int mod = 1e8;
    int dp[105][105][23];
    int rec(int i,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int prev) {
        if(i==m && target==0) return 0;
        if(i==m || target<0) return mod;
        if(dp[i][target][prev]!=-1) return dp[i][target][prev];
        if(houses[i]!=0) {
            if(houses[i]!=prev) return dp[i][target][prev]=rec(i+1,houses,cost,m,n,target-1,houses[i]);
            return dp[i][target][prev]=rec(i+1,houses,cost,m,n,target,houses[i]);
        }
        int ans = mod;
        for(int k=1;k<=n;k++){
            houses[i] = k;
            if(k!=prev)ans = min(ans,cost[i][k-1]+rec(i+1,houses,cost,m,n,target-1,houses[i]));
            else ans = min(ans,cost[i][k-1]+rec(i+1,houses,cost,m,n,target,houses[i]));
            houses[i] = 0;
        }
        return dp[i][target][prev]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,houses,cost,m,n,target,21);
        if(ans>=mod) return -1;
        return ans;
    }
};