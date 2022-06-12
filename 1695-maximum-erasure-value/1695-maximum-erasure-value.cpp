class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n= nums.size();
            unordered_set<int> st;// store unique elemets of curr Subarray
            int currSum=0;
            int maxSum=0;
            int i=0,j=0;
            while(j<n){
                    currSum+=nums[j];
                    if(st.find(nums[j])==st.end())  st.insert(nums[j]);
                    else{
                            while(nums[i]!=nums[j]){
                                    currSum-=nums[i];
                                    st.erase(nums[i]);
                                    i++;
                            }
                            //here nums[i]==nums[j]
                            currSum-=nums[i];
                            //no need to erase from set here, as nums[j] vhi hai
                            i++;
                    }
                    // here i to j is a subarray with unique elements
                    maxSum=max(currSum,maxSum);
                    j++;
            }
            return maxSum;
            
            
    }
};