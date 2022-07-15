class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        //3 states of dp - index,m,n
        //top down
          vector<vector<vector<int>>> dp(s,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
           return findmax(strs,m,n,0,dp);
    }
    //m zeroes, n ones
     int findmax (vector<string>& strs, int m, int n,int index,vector<vector<vector<int>>>&dp)
     {
         if(index==strs.size())return 0;
         if(dp[index][m][n]!=-1)return dp[index][m][n];
         
         int countzeroes = count(strs[index].begin(),strs[index].end(),'0');
         int countones = strs[index].size()-countzeroes;
         
         if(m-countzeroes>=0 && n-countones>=0) dp[index][m][n]= max(1+findmax(strs,m-countzeroes,n-countones,index+1,dp), 
         findmax(strs,m,n,index+1,dp)); //inc and exc
         else dp[index][m][n]=findmax(strs,m,n,index+1,dp);
         
         return dp[index][m][n];     
     }
};