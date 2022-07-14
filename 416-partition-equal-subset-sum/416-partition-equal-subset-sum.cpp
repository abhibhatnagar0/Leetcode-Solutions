class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        for (auto a : nums) // Sum up the array
            sum += a;
        
        if (sum % 2) // If the sum is odd - we can never find two equal partitions
            return false;
        
        sum /= 2;
        return subsetsum(nums,sum,n);
    }
    
    //finding if a subset is possible with given sum
     bool subsetsum(vector<int> &nums, int sum, int n)
    {
        bool dp[2][sum + 1];
        for (int i = 0; i < 2; ++i) dp[i][0] = 1;
        for (int j = 1; j < sum + 1; ++j) dp[0][j] = 0;

        for (int i = 1; i < n + 1; ++i){
            for (int j = 1; j < sum + 1; ++j){
                if (nums[i - 1] <= j)
                    dp[i%2][j] = dp[(i - 1)%2][j] || dp[(i - 1)%2][j - nums[i - 1]];
                else
                    dp[i%2][j] = dp[(i - 1)%2][j];
            }
        }
        return dp[n%2][sum];
     }
};