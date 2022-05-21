class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= 0 || nums[i] > n) //ignore numbers not in range of {1, n-1}
                continue;
            else
            {
                if(nums[nums[i]-1]==nums[i])  //already in correct place, then skip (else infinite loop of swapping)
                    continue;
                swap(nums[i], nums[nums[i] - 1]);
                --i;                          //can't go forward without putting swapped number in correct place.
            }
        }
        
        for(int i = 0; i < n; ++i)
            if(i + 1 != nums[i])
                return i + 1;
        return n + 1;
    }
};
