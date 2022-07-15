class Solution {
public:
        vector<vector<int>> allperm;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
if(nums.size()==1) return {nums};  //for n numbers, n! permutations are possible
            
             helper(nums,0); //0 is position of index to be fixed
            return allperm;     
    }
        void helper(vector<int>& nums, int pos){
                //pos se phle wale indexes are all fixed, so dont look at them.
                if(pos==nums.size()){ 
                        allperm.push_back(nums); 
                        return;
                }
            //no two nums[i] with same value can come at pos
            //making a unique set for each pos storing all nums[i] swapped with nums[pos]
                unordered_set<int> st;
            for(int i=pos;i<nums.size();i++){ 
                    if(st.find(nums[i])!=st.end()) continue; //nums[i] ko already swap krva chuke h nums[pos] ke saath
                
                    st.insert(nums[i]); 
                    swap(nums[i],nums[pos]);  // nums[i] ko fix krna h at pos index
                    helper(nums,pos+1);       
                    swap(nums[i],nums[pos]);  //backtracking step after recursive call
            }
        }
};