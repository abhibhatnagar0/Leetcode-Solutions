class Solution {
public:
        int dp[1010][1010];
    string longestPalindrome(string s) {
            int start=0;
            int length=0; // end-start+1
            memset(dp,0,sizeof(dp));
            int n=s.size(); //5
            int len=1;
           for(int diff=0; diff<n; diff++){ // 0,4 so diff upto 4
                    for(int i=0,j=diff ; j<n ; i++,j++){                   //00 01 02 03 04
                                                                           //11 12 13 14
                                                                           //22 23 24
                                                                           //33 34
                                                                           //44   
                            if(diff==0) //n=1 
                                    dp[i][j]=1;
                            else if (diff==1) //n=2  
                            {  if(s[i]==s[j])
                                          dp[i][j]= 1;
                               else dp[i][j]=0;
                             }     
                            
                            else {
                    if(s[i] == s[j] && dp[i+1][j-1]==1)dp[i][j]=1;
                    else dp[i][j]=0;
                } 
                            if(dp[i][j]==1){
                                   if(diff+1>=length){
                                           length=diff+1;
                                           start=i;
                                   }
                            }
            }  
           }
            string ans = s.substr(start,length);
            return ans;
            
            
        
    }
};