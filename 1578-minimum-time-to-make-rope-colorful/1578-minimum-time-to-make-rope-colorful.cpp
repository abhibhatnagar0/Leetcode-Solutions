class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
         int mincost=0,n=colors.size();
        if(n==1) return 0;
        
        int maxval=neededTime[0];
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                if(maxval>neededTime[i])
                {
                    mincost+=neededTime[i];
                }
                else
                {
                    mincost+=maxval;
                    maxval=neededTime[i];
                }
                    
            }
            else
            {
                maxval=neededTime[i];
            }
        }
        return mincost;
    }
};