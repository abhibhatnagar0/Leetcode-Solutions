class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        return helper(n,dp);
    }
    int helper(int n,vector<int> &dp){
        if(n==0 || n==1 || n==2 || n==3) return n;
        if(dp[n]!=0)return dp[n];
        
        int ans=n-1;
        for(int i=1;i*i<=n;i++){
            ans= min(helper(n-i*i,dp),ans);
        }
        return dp[n]= ans+1;
        
    }
};