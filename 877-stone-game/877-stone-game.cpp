class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // dp[i][j]: the maximum number of stones in total a player can pick from i,j
     int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
     for (int i = 0; i < n; ++i) dp[i][i] = piles[i];
     for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
           dp[i][j] = max(piles[i] + dp[i + 1][j], piles[j] + dp[i][j - 1]);
         }
    }
        //for Alice to win -> dp[0][n - 1] > max(dp[1][n - 1], dp[0][n - 2])
        
     return dp[0][n - 1] > max(dp[1][n - 1], dp[0][n - 2]);
    }
};