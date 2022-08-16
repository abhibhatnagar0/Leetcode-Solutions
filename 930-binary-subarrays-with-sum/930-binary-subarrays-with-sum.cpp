class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {            unordered_map<int,int> m;
 int sum=0,count=0;
 m[0]=1;
    for(auto &x: nums){
        sum += x;
        if(m.find(sum - goal) != m.end())
        {
            count += m[sum-goal];
        }
        m[sum]++;
    }
    return count;
    }
};