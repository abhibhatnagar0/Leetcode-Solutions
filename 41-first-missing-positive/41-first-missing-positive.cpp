class Solution {
public:
        //cyclic sort easy qn
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
            
 //just put nos in [1,n] at their correct position
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= 0 || nums[i] > n) //ignore numbers not in range of {1, n}
                continue;
            else
            {
                if(nums[nums[i]-1]==nums[i])
                    continue;
                 swap(nums[i], nums[nums[i] - 1]);
                    i--;
                                       
            }
        }
  //starting se traversing pe, jo idx pe no nhi mila, that idx+1 is no.
  //saare idx pe  correct no aaya, ie [1,n] all present in nums, so return n+1          
        for(int i = 0; i < n; ++i)
            if(i + 1 != nums[i])
                return i + 1;
        return n + 1;
    }
};
