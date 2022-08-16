class Solution {
public:
    int numberOfSubarrays(vector<int>&nums, int k) {
        int n= nums.size();
        for(auto & x:nums){
            if(x&1) x=1;
            else x=0;
        }
        //now, subarrays with k odd numbers is same as
        //subarrays with sum k
        unordered_map<int,int>mp;
        int sum=0,cnt=0;
        int i=0;
        while(i<n){
            sum+=nums[i];
            if(sum==k) cnt++;
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
            i++;
        }
        return cnt;
    }
};