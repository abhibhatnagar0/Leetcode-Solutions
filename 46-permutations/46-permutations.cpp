class Solution {
public:
        vector<vector<int>> allperm;
    vector<vector<int>> permute(vector<int>& nums) {
            if(nums.size()==1) return {nums};  //for n numbers, n! permutations are possible
            
             helper(nums,0); //0 is position of index to be fixed
            return allperm;     
    }
        void helper(vector<int>& nums, int pos){
                //pos se phle wale indexes are all fixed, so dont look at them.
                if(pos==nums.size()){ //when nth index is to be fixed or sb fix ho chuke hai
                        allperm.push_back(nums); //return current status of nums after swappings
                        return;
                }
            //only elements after pos can be swapped with it 
            //we will place all elements one by one at 0 index(pos) and ask recursion
            //to do remaining task of putting elements after pos+1 
            for(int i=pos;i<nums.size();i++){ 
                
                    swap(nums[i],nums[pos]);  // nums[i] ko fix krna h at pos index
                    helper(nums,pos+1);       
                    swap(nums[i],nums[pos]);  //backtracking step after recursive call
            }
        }
        
};