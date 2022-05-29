class Solution {
public:
    int totalSteps(vector<int>& nums) {
           int n=nums.size(),ans=0,cnt=0;
        
        stack<pair<int,int>> st;
        st.push({nums[n-1],0});
        for(int i=n-2;i>=0;i--)
        {
             cnt=0;
            while(!st.empty()&&nums[i]>st.top().first)
            {   cnt++;
                cnt=max(cnt,st.top().second);
                st.pop();
            }
            ans=max(ans,cnt);
            st.push({nums[i],cnt});
        }
        return ans;       
    }
};