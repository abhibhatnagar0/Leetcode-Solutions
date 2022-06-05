class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int n=nums.size();
            for(int i=0;i<n;i++){
                    int x= abs(nums[i])-1;
                    if(nums[x]<0) return abs(nums[i]);
                    else nums[x]*=(-1);  
            }
            return -1;
            //if all numbers lie in [1,n], number-1 gives a index corresponding to that no.
            //from all numbers in array, go to their sorresponding idx's number, make it neg
            //if we are sent to idx x by idx i such that nums[x] is neg,  nums[i] is dup
    }
};