class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int n =nums.size();
         vector<int> ans (n,0) ;
        // for a case where all nos are positive/negative
        if(nums[n-1]<0){
        
            for(int p=n-1;p>=0;p--){
                ans[n-(p+1)]= nums[p]* nums[p];
                
            }
        }
          
        if(nums[0]>=0){
            for(int p=0;p<=n-1;p++){
                ans[p]= nums[p]* nums[p];
            }
        }
        if(ans[n-1]!=0) //agar aa gya ans ab tk then return
            return ans;
        
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