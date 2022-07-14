class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            target = abs(target);
       
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i]; 
        }
        // s1 + s2 = sum
        //s1-s2= target
        long long sum_s1= (sum+target)/2;
        if(target > sum || (sum + target) % 2 == 1)   return 0;
        return count_subsets(nums,sum_s1);
        
    }
        
    int count_subsets(vector<int>& nums, long long sum_s1){
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum_s1 +1,0));
        for(int i=0; i<=n;i++)
            dp[i][0]=1; // not always true for 0 in nums
        for(int j=1; j<=sum_s1; j++)
            dp[0][j]=0;  
            
        for(int i=1;i<=n;i++){
            for(int j=0; j<=sum_s1; j++){ //include j=0 as well
                if(nums[i-1]>j)
                        dp[i][j]= dp[i-1][j];
                else
                    //this will be executed also when nums[i-1]=j=0
                        dp[i][j]= dp[i-1][j] + dp[i-1][j-nums[i-1]] ; 
            }
        }
      return dp[n][sum_s1];
    }
};
