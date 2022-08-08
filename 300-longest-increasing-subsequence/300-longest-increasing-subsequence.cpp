class Solution {
public:
       
    int lengthOfLIS(vector<int>& nums) {
            int n= nums.size();
             vector<int> dp(n,1);
            dp[0]=1;
            int longest_length=1;
            for(int i=1; i<n;i++){
                    for(int j=0; j<i; j++){
                            if(nums[j]<nums[i]){
                                    dp[i]=max(dp[i],dp[j]+1);
                        // dp[i] gives ith idx pe end krne wala max len ka inc subq
                            }
                    }
                   longest_length=max(longest_length, dp[i]);
            }
         return longest_length;   
        
    }
};