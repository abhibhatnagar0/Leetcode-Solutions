class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
            int sum=0;
            unordered_map <int,int> mp;
            //mp stores rem and its index for finding len of subarray
            mp[0]=-1; //as idx=0 se idx=3 ka subarray has size=4...ie (3-(-1))
           
            for(int i=0;i<n;i++){
                    sum+=nums[i];
                    int rem=sum%k;
                    if(mp.find(rem)!=mp.end()){
                            if(i-mp[rem]>=2) return true;
                    }
                    else mp[rem]=i;
                    
                   
            }
            return false;
    }
};