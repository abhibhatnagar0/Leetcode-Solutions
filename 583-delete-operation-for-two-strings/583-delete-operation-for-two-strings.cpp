class Solution {
public:
    int minDistance(string word1, string word2) {
          int m= word1.size();
        int n= word2.size();
            //first find common subsequence
            vector<vector<int>> dp(m+1,vector<int>(n+1,0));
            
            for(int i=1;i<m+1;i++){
                  for(int j=1;j<n+1;j++){
                         if(word1[i-1]==word2[j-1])
                           dp[i][j]= 1+dp[i-1][j-1];
                         else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                    }
            }
            int delFromWord1 = m- dp[m][n];
            int delFromWord2 = n- dp[m][n];
            return delFromWord1 + delFromWord2;
    }
};