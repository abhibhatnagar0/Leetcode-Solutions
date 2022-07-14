class Solution {
public:
    int change(int amount, vector<int>& coins) {
            vector<int> dp(amount+1, 0);
          dp[0] = 1;
        //total combinations
            for(int i=0; i<coins.size() ; i++ ){ //first complete one coin type
                                                    //for all amounts
                    for(int j=1; j<=amount; j++){
                            if(j-coins[i]>=0)
                            dp[j] += dp[j-coins[i]];
                    }
            }
            return dp[amount];
    }
};