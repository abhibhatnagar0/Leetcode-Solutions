class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int n = candidates.size();
        vector<vector<vector<int>>> dp(target + 1);
    dp[0] = {{}};
    for (int j = 0; j < n ; j++) // all combinations
    {
         for (int i = candidates[j]; i <= target; i++)
        {  
              for(vector<int> v : dp[i-candidates[j]]){
               v.push_back(candidates[j]);
                dp[i].push_back(v);  
              }
        }    
    }
    return dp[target];
    }
};