class Solution {
public:
    int findMin(vector<int>& nums) {
        //prop of a rotated sorted array
    //it has 2 increasing(non-str) parts with a dip in btw
    //element at dip is the minimum lying at bottom of 2nd inc part
    //all values of 2nd inc part are smaller than 1st inc part
    //ie nums[end]<nums[start] in a rotated sorted array
            
            int n=nums.size();
            if(n==1) return nums[0];
            if(nums[0]<nums.back()){
                    return nums[0]; // sorted array is not rotated
            }
            
            int s=0,e=n-1;
            while(s<e){
                    int m= s+ (e-s)/2;
                    if(nums[m]>nums[e]){
                            //mid lies in 1st inc part
                            //dip lies in 2nd inc part
                            s=m+1; //mid cannot be dip ofc
                    }
                    else if(nums[m]==nums[e]){
                            //mid can lie in any part
                            e--;//just to reduce size        
                    }        
                     else{       //mid lies in 2nd inc part
                            e=m;  //mid can be the dip
                      }      
            }
            //here s==e==m==dip
            return nums[s];
    }
        // time is o(logn) in avg case 
        //         o(n) in worst case
};