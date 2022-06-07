class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
            int n=nums.size();
            
            if(n==0) return {-1,-1};
            
            int s=0,e=n-1;
            while(s<=e){
                    int mid=s+(e-s)/2;
                    if(nums[mid]==target){
                            first=mid; //temporarily storing ans, not sure if its the 1st occurce
                            e=mid-1; //to check for target in left
                    }
                    else if(nums[mid]>target){
                            e=mid-1;       
                    }
                    else s=mid+1;
            }
            
            s=0,e=n-1;
            
             while(s<=e){
                    int mid=s+(e-s)/2;
                    if(nums[mid]==target){
                            last=mid;
                            s=mid+1;
                    }
                    else if(nums[mid]>target){
                            e=mid-1;       
                    }
                    else s=mid+1;
            }
            
            return {first,last};
            
    }
};