class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
            if(n==1){
                    if(nums[0]==target) return 0;
                    else return -1;
            }
            
            int s=0,e=n-1;
            
          while(s<=e){
                    int m=s+(e-s)/2;
                    if(nums[m]==target) return m;      
           //mid always lies in part that is inc, with other part dec(having dip)
                    
                   if(nums[m]>=nums[s]){ //s to m forms an inc part
                       if(nums[m]>target && target>=nums[s]){
                          //target lies btw s and m
                            e=m-1;
                        }
                        else s=m+1;
                   }
                    else{
                        // s to m is not inc, 2nd part m to e is increasing.
                          if(nums[m]<target && target<=nums[e]){
                          //target lies btw s and m
                            s=m+1;
                        }
                        else e=m-1;        
                    }          
    }
            //here s>e, hence ans aana hota toh aa jata
            return -1;
    }
};