class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        if(n<=1) return 0;
        vector<int> buy(2,0);
        vector<int> sell(2,0);
        // buy[i] represents the max profit at day i in buy status
        // (the last action you took is a buy action)
        // sell[i] represents the max profit at day i in sell status
        // (the last action you took is a sell action)
        
        //assume transaction fee paid on selling a stock
        buy[0]= -prices[0];
        sell[0]= 0;
        for(int i=1;i<n;i++){
            buy[i%2]=max(buy[(i-1)%2],sell[(i-1)%2]- prices[i]);
            // keep the same as day i-1, or buy from sell status at day i-1
            sell[i%2]=max(sell[(i-1)%2],buy[(i-1)%2]+prices[i]-fee);
            // keep the same as day i-1, or sell from buy status at day i-1
        }
        return sell[(n-1)%2];
    }
};