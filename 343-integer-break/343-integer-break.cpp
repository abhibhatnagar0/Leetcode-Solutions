class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
     int helper(int n,vector<int>&dp) {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int maxi=0;
        
        for(int i=1;i<n;i++){
            int p= max(helper(n-i,dp)*i,i*(n-i));
            maxi=max(maxi,p);
        }
        return dp[n]=maxi;
    }
    // f(5)= max (1*f(4), 2*f(3), 3*f(2), 4*f(1))
    // we have to brk 5 into atleast 2 integers
    //     we broke in into 2 with one constant val (by for loop)
    //     other val can itself be further broken or can be used as it is
    //     like 2,3 when broken gives 1,2 respectively
    //     so better to use 2,3 as it is
        
        
};