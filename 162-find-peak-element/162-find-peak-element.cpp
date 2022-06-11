class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
            int s=0,e=n-1;
            while(s<e){
                    int m= s+ (e-s)/2;
                    if(nums[m]<nums[m+1]){
                            //ans right side me pkka aayega (excluding m)
                            //left me bhi aa skta h, but right me for sure aayega
                            s=m+1;
                    }
                    else if (nums[m+1]<nums[m]){
                            e=m;
                            //e=m for case where nums[m-1]<nums[m] ie m is peak
                            //when nums[m-1]>nums[m].... ans will pkka be in left
                    }
             // nums[i] cannot be equal to nums[i+1]      acq
                   
            }
            //when s==e==m
            return s;
    }
};