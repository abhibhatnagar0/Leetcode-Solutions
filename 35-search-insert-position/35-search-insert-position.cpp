class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
            int s=0,e=n-1;
            //if target not found, find just smaller element
            int justSmalleridx=-1;
            while(s<=e){
                    int m=s+(e-s)/2;
                    if(nums[m]==target){
                            return m;
                    }
                    else if(nums[m]>target){
                            e=m-1;
                    }
                    else{   //nums[m]<target
                            justSmalleridx=max(justSmalleridx,m);
                            s=m+1;//so as to find bigger next smaller
                    }
            }
           return justSmalleridx+1; 
    }
};