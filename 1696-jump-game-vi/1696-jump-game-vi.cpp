class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n= nums.size();
        
        vector<int>dp(n);  //dp[i] stores max cost from ith index to last index
        dp[n-1]=nums[n-1];
        priority_queue<pair<int,int>> maxh; //max heap to store {dp[index], index}
        maxh.push({dp[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(maxh.size() && maxh.top().second>i+k) maxh.pop(); //we keep popping elements that are out of our window of size k to find the first top element inside our range.
            dp[i]=maxh.top().first+nums[i]; //That will be our max cost so we add it + current index cost
            maxh.push({dp[i],i}); // then we push the current dp[i] and i into max heap
        }
        return dp[0];  
    }
};