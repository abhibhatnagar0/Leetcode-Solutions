class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minBefore=INT_MAX; //buying cost
        int profit=0;
        for(int i=1;i<n;i++){
             minBefore= min(prices[i-1],minBefore);
            if(prices[i]- minBefore > profit ){
                profit= prices[i]- minBefore;
            }  
        }
        return profit;
    }
};