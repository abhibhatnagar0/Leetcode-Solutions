class Solution {
public:
    // p= "abde*w." can be "abd"+ "n time e" +"w"+ "any char"
    //n can be 0,1,2,3.....
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        
        //dp[i][j] tells if i,j length of p,s are taken
        //s and p can be made equal or not
        dp[0][0] = true;
        for(int i=1; i<m+1; i++){ //if s.size()=0 
            if(p[i-1] == '*'){
                dp[i][0] = dp[i-2][0]; // i-2 ke baad p can have "c*"=""
            }
        }
        for(int j=1; j<n+1; j++){ //1st row
            dp[0][j] = false;
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){ //p[i-2] is repeated char(0 to any no of times)
                    if(p[i-2] == s[j-1] || p[i-2] == '.'){
                        dp[i][j] = dp[i][j-1] || dp[i-2][j];
                        // (removing last char of each,removing c*)
                    }
                    else{
                        dp[i][j] = dp[i-2][j]; 
                        //so only option is removing c*
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};