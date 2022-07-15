class Solution {
public:
    int integerBreak(int n) {
    vector < int > dp(n + 1, INT_MIN);
      dp[0] = dp[1] = 1;
        
      for (int i = 2; i <= n; i++){
        for (int j =1;j<=i-1;j++){
          dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
        }
      }
      return dp[n];
    }
    // f(5)= max (1*f(4), 2*f(3), 3*f(2), 4*f(1))
    // we have to brk 5 into atleast 2 integers
    //     we broke in into 2 with one constant val (by for loop)
    //     other val can itself be further broken or can be used as it is
    //     like 2,3 when broken gives 1,2 respectively
    //     so better to use 2,3 as it is
        
        
};