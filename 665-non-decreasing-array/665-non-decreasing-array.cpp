class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
            int dips=0;
            int idx; //index of last dip/only dip
            for(int i=1;i<n;i++){
                    if(nums[i]<nums[i-1]){
                            dips++;  //checking dip at ith index    
                            idx=i;
                    }
            }
         if(dips==0) return true; // increasing array
         else if(dips>=2) return false; // just one modification cannot make it non-decreasing
         else{ //just one dip at idx th index
                    if(idx==1 || idx==n-1) return true;
                    if(nums[idx+1]>=nums[idx-1]) return true;
                    else{
                            if(nums[idx-2]>nums[idx]) return false;
                            else return true;
                        }       
            }
           
            
            
    }
};