class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
    
        return max(helper(0,n-2,nums,dp1),helper(1,n-1,nums,dp2));
    }
    int helper(int sidx, int eidx,vector<int>& nums,vector<int>& dp){
        if(sidx > eidx) return 0;
            
         if(dp[sidx]!=-1) return dp[sidx];
        
         int op1 = helper(sidx+2,eidx,nums,dp)+ nums[sidx];
         int op2 = helper(sidx+1,eidx,nums,dp);
        return  dp[sidx]= max(op1,op2);
        
    }
};