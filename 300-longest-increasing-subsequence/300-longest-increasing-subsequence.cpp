class Solution {
public:
        int dp[2510][2511];
    int lengthOfLIS(vector<int>& nums) {
           memset(dp,-1,sizeof(dp));
            
           return lis_helper(nums,0,-1);
    }
           int lis_helper(vector<int>& nums, int i, int prev){
                if(i==nums.size()) return 0;  
                
                if(dp[i][prev+1]!=-1) return dp[i][prev+1];
                   
                int op1=0;
                if(prev==-1 || nums[i]>nums[prev]){
                        //including i in lis
                         op1= 1 + lis_helper(nums,i+1,i);
                }
                
                 int op2= lis_helper(nums,i+1,prev); //excluding i, so prev phle wala hi 
                   
                        return dp[i][prev+1]= max(op1,op2);
                }
        //changing variable passes...state of dp is 2
        // i lies from 0 to n-1
        //prev lies from -1 ro n-1... so prev+1 passed in dp array
};