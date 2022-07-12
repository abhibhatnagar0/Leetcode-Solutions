class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        //Atmost 2 transaction
        //both left and right take care of 1-1 transaction
        vector<int>left(n,0);
        //left[i] means max profit earned so far till i by selling on i or before
        //buying at min so far from starting
        left[0]=0;
        int minBefore=prices[0];//buying price
        for(int i=1;i<n;i++){
            minBefore= min(minBefore,prices[i]);
            left[i]= max(left[i-1], prices[i]-minBefore);
        }
        
        vector<int> right(n,0);
        //right[i] means max profit earned by buying on i or before
        //selling at max so far from end
        right[n-1]=0;
        int maxAfter= prices[n-1]; //selling price
        for(int i=n-2;i>=0;i--){
            maxAfter= max(maxAfter,prices[i]);
            right[i]= max(right[i+1], maxAfter-prices[i]);
        }
        int maxProfit=0;
        for(int i=0;i<n;i++){
            int profit= left[i] + right[i];
            maxProfit=max(profit,maxProfit);
        }
        return maxProfit;
    }
    //we can buy and sell on the same day as well
};