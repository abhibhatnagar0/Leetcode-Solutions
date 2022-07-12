class Solution {
public:
   vector<int> dp;
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {        
        dp.resize(367,0);
        int n = days.size();
        return sub(days,costs,0,n);    
    }
    
    int sub(vector<int> &day, vector<int> &cost, int si, int n)   
    {
        if(si>=n)   return 0;
        
        if(dp[si]!=0)  return dp[si];      
        
        int cost_day = cost[0] + sub(day , cost , si+1, n);
        
        int i=si;
        while(i<n && day[i]<day[si]+7){
            i++;
        }
        int cost_week = cost[1] + sub(day, cost, i, n);
        
        i=si;
        while(i<n && day[i]<day[si]+30){
            i++;
        }
        int cost_month = cost[2] + sub(day, cost, i, n);     
        
        return dp[si]= min({cost_day, cost_week , cost_month  }); 
    } 
    
};