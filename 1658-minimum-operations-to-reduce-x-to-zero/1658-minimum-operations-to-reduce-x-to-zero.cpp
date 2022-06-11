class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    /*nums ki starting and ending se kuch ele nikalne hai
      such that unka sum x ho, and minimum no of ele niklalne hai.
      this is eq to 
      finding a subarray in middle of nums of sum.... total-x
      nums.size()-subarray.size()= no of operations (min) */
            
            int n= nums.size();
            if(n==1) {
                    if(nums[0]==x) return 1;
                    else return -1;
            }
            int total=0;
            for(auto p: nums) total+=p;
          
            if(total==x) return n;
            //finding subarray of maximun length with sum total-x
            int sum=0; //prefix sum
            unordered_map <int,int> mp; //{sum,idx}
            mp[0]=-1; //subarray starting from 0 idx
            int maxlen=0;
            for(int i=0;i<n;i++){
                    sum+=nums[i];
                    if(mp.find(sum-(total-x))!=mp.end()){
                            maxlen=max(maxlen,i-mp[sum-(total-x)]);
                    }
                    mp[sum]=i;
            }
            if(maxlen==0) {
                    //no subarray can have sum=total-x 
                    return -1;
            }
            return n-maxlen; //gives min part of nums from left and right with sum X
    }
};