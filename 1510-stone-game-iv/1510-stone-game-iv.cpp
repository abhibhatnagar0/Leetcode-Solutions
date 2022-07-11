class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        if(n==1) return true;
        if(n==2) return false;
        //dp[i] tells if current player can win or not with n stones in pile
        dp[0]= false;
        dp[1]=true;
        dp[2]=false;
        for(int i=3;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};