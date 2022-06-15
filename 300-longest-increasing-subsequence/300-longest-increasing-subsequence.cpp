class Solution {
public:
        
    int lengthOfLIS(vector<int>& nums) {
            int n= nums.size();
            vector<vector<int>> dp(n, vector<int>(n+1,-1));
           
           return lis_helper(nums,0,-1,dp);
    }
           int lis_helper(vector<int>& nums, int i, int prev, vector<vector<int>>& dp){
                if(i==nums.size()) return 0;  
                
                if(dp[i][prev+1]!=-1) return dp[i][prev+1];
                   
                int op1=0;
                if(prev==-1 || nums[i]>nums[prev]){
                        //including i in lis
                         op1= 1 + lis_helper(nums,i+1,i,dp);
                }
                
                 int op2= lis_helper(nums,i+1,prev,dp); //excluding i, so prev phle wala hi 
                  
                        return dp[i][prev+1]= max(op1,op2);
                }
        //changing variable passes...state of dp is 2
        // i lies from 0 to n-1
        //prev lies from -1 ro n-1... so prev+1 passed in dp array
};