class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int n= nums.size();
            if(n==1) {
                    if(nums[0]==x) return 1;
                    else return -1;
            }
            int total=0;
            for(auto p: nums) total+=p;
          
            if(total==x) return n;
            if(total<x) return -1;
            
            //finding subarray of maximun length with sum total-x
               //using sliding window
            int target =total-x;
            int j=0,i=0;
            int sum=0;// stores sum of curr window
            int maxlen=0;
            //j can expand window, i can shrink window 
            while(j<n){
                  sum+=nums[j];
                    while(sum>target){
                            sum -= nums[i++];
                       //keep shrinking window until sum becomes less than or equal to target    
                    }
                    if(sum<target){
                            j++;
                    }
                    else if(sum==target) {
                        maxlen=max(maxlen,j-i+1);  
                            j++;
                    }
            }
            if(maxlen==0) return -1;
            
            return n-maxlen;
            
    }
};