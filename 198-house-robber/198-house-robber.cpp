class Solution {
public:
    int rob(vector<int>& nums) {
       int n= nums.size(); //n houses
        vector<int>dp(n,-1);
        return helper(0,n,nums,dp); 
    }
    int helper(int i,int n, vector<int>& nums, vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= max(nums[i]+helper(i+2,n,nums,dp), helper(i+1,n,nums,dp));
    }
};