class Solution {
public:  
    
    bool winnerSquareGame(int n) 
    {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
   //solve(n) will tell if current player(whose chance is there)
   //with n stones kept on pile can win or not 
    
    bool solve(int n, vector<int>&dp) 
    { 
        //will return Alice with n stones can win or not
        if(n==0) return false; //empty pile
        if(dp[n]!=-1) return dp[n];
        for(int i=1; i*i<=n; i++)
            if(solve(n-i*i, dp)==false) return dp[n]=true;
        return dp[n]=false;
    }    
          //if Alice takes i*i stones
            //Bob sees n-i*i stones in pile
            //if for any i, bob looses, he will loose as Alice too 
            //will play optimally(will win if she can win)
  
};