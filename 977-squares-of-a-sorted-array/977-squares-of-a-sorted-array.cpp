class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int n =nums.size();
         vector<int> ans (n,0) ;
        
        
            int l=0;
            int r=n-1;
            int p=n-1;
            while(l<=r){
                    if(abs(nums[l])<abs(nums[r])){
                       ans[p--]=nums[r]*nums[r];    
                           r--; 
                    }
                    else{
                            ans[p--]=nums[l]*nums[l];
                            l++;
                    }
            }
      return ans;
    
    }        

};