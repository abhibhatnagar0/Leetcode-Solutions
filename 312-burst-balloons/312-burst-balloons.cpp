class Solution {
public:
    int maxCoins(vector<int>& nums) {
         int n=nums.size();
         int dp[n][n];
        
        //dp[i][j] stores max coins we can get on bursting baloons from (i,j) out of total nums array.
        //for finding dp[i][j]..select a val k in btw i to j that is to be burst at last after bursting (i,k-1) and (k+1,j)
        //bursting k will give coins = nums[i-1]*nums[k]*nums[j+1]
        
        for(int g=0;g<n;g++)
        {
            for(int i=0, j=g;j<n;i++,j++)
            {
                int maxCoins=0; //for(i,j)
                for(int k=i;k<=j;k++)
                {
                    int left = (i==k)?0:dp[i][k-1];
                    int right = (j==k)?0:dp[k+1][j];
                    int val = ((i == 0)?1:nums[i-1])*nums[k]*((j==n-1)?1:nums[j+1]);
                    maxCoins=max(maxCoins,left+right+val);
                }
                dp[i][j]=maxCoins;
            }
        }
        return dp[0][n-1];
    
    }
};