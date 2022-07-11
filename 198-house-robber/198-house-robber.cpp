class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        // vector<int> dp(n+1,0);
        //dp[i] means max value gained if i houses are there to rob
        int dp[2]={0};
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i%2]= max(dp[(i-2)%2]+nums[i-1], dp[(i-1)%2]);
        }
        return dp[n%2];
    }
};