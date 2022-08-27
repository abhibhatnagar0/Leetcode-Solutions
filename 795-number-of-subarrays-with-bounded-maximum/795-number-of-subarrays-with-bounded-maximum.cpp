class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n= nums.size();
        int i=0,j=0;
        int cnt=0,last=0;
        while(j<n){
            if(nums[j]>=left && nums[j]<=right){ //nums[j] can be max val
                cnt+=(j-i+1); //adding subarrays which end with val in range
                last= j-i+1;
            }
            else if(nums[j]>right){
                i=j+1;
                last=0;
            }
            else{
               cnt+=last; //adding subarrays after sticking small val to val in range
            }
            j++;
        }
        return cnt;
    }
};