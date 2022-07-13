class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<=1) return 0;
     	// All the variables below are in terms of profit we have 
	// Bought for the first time
	int bought1 = -1 * prices[0];
	// Sold for the first time
	int sold1 = 0;
	// Bought for the second time
	int bought2 = INT_MIN;
	// Sold for the second time
	int sold2 = 0;

	for(int i = 1; i < prices.size(); i++) {
		bought1 = max(bought1, -1 * prices[i]);
		sold1 = max(sold1, bought1 + prices[i]);
		bought2 = max(bought2, sold1 - prices[i]);
		sold2 = max(sold2, bought2 + prices[i]);
	}

	return sold2;
    }
};