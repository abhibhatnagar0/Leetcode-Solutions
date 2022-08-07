class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long good_pairs = 0;
        long long n = nums.size();
        
        // for bad pairs   j - i != nums[j] - nums[i]
        // for good pairs  j - i == nums[j] - nums[i]
        //     or
        //                 j-nums[j]==i-nums[i]
            
        map<int, int> mp; //stores old values of i-nums[i] with their frq
        
        for (int i = 0; i < n; i++) {
            int cur = i - nums[i];
            good_pairs += mp[cur];//pair i with all curr values
            mp[cur] ++;
        }
        
        long long total = n*(n-1)/2;
        return total - good_pairs;
    }
};