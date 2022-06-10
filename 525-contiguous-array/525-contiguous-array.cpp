class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
            int runningSum=0;
            //consider all 0s as -1s in array runningSum
            unordered_map<int,int> mp; //{runningSum,idx}
            mp[0]=-1;//for subarray starting at idx 0
            int maxlen=0;
            for(int i=0;i<n;i++){
                    
                    if(nums[i]==0) runningSum+=(-1);
                    else runningSum+=nums[i];
                    
                    if(mp.find(runningSum)!=mp.end()){
                            maxlen=max(maxlen, i-mp[runningSum]);
                    }
                    else{
                            mp[runningSum]=i;
                    }
  
            }
         return maxlen;   
    }
};