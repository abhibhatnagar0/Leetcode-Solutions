class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
            int n= nums.size();
       vector<unsigned int> dp (target+1,0);
            dp[0]=1; 
            for(int i=1 ; i<=target; i++){ //permutations 
                    for(int j=0; j<n; j++){
                            if(i>=nums[j]) dp[i]+= dp[i-nums[j]];
                            else continue;
                    }
            }
          return dp[target];  
    }
};