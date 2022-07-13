class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        if(n<=1) return 0;
      
      vector<int>buy(2,0);
      vector<int>sell(2,0);
      vector<int> cool(2,0);
      
      buy[0]=-prices[0];
      sell[0]=0;
      cool[0]=0;
     
      for(int i=1;i<n;i++)
      { 
        buy[i%2]=max(buy[(i-1)%2],cool[(i-1)%2]-prices[i]);
        sell[i%2]=max(sell[(i-1)%2],buy[(i-1)%2]+prices[i]);
        cool[i%2]=max(cool[(i-1)%2],sell[(i-1)%2]);
      }
        return max(cool[(n-1)%2],sell[(n-1)%2]);
        //if we sell on n-1th day, then no need for cooldown as we wont buy after that
    }
};