class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int, int> mp;
          //stores sum and its freq  
        int count = 0, sum = 0;
        for (auto n: nums) {
            sum += n;
             if(sum==k) count++; //shuru se le kr ab tk ka subarray ...either write this or mp[0] and next line sidha
                
                if(mp.find(sum-k)!=mp.end())
            count += mp[sum - k]; // abhi sum=20 pe h, sum=15 agar 3 baar aa rkha h
                // so, 3 subarrays more  (k=5)
            mp[sum]++;
        }
        return count;
    }    
};