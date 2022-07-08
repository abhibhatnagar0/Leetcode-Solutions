class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[0],max(nums[1],nums[2]));
        vector<int>dp(n+1,0);
        //choosing idx=0, so wont be able to choose idx=1 and idx=n-1
        dp[0]=0;
        dp[1]= nums[0];
        dp[2]= nums[0];
        for(int i=2;i<n-1;i++){ 
            dp[i+1]=max(dp[i-1]+nums[i], dp[i]);
        }
        //can choose idx=n-1 and idx=1...but cannot choose idx=0
         vector<int>dp2(n+1,0);
        dp2[2]= nums[1];
        dp2[3]= max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            dp2[i+1]=max(dp2[i-1]+nums[i], dp2[i]);
        }
        
        return max(dp[n-1],dp2[n]);
    }
};