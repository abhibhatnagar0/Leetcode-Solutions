class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int firstBuy=INT_MAX,profit1=0,secondBuy=INT_MAX,profit2=0;
		
        for(int currPrice : prices)
        {
            firstBuy=min(firstBuy,currPrice);   // minimum price for 1st buy (min so far)
            profit1=max(profit1,currPrice-firstBuy);    
            // maximum profit after 1st sell= max(earlier profit1, profit1 after selling on currDay)
            secondBuy=min(secondBuy,currPrice-profit1);        
            // minimum price for 2nd buy after removing profit from 1st sell(effective buying cost)
            profit2=max(profit2,currPrice-secondBuy);      // maximum profit after 2nd sell
           
        }
         return profit2;
    }
};