class Solution {
public:
    bool isPossible(vector<int>& nums) {
         unordered_map<int, int> left; //stores freq of all elements
        //the left out freq, which is not part of any subsequence yet
        
        unordered_map<int, int> seq; //seq[ele] stores freq of subsequences ending at ele
        
        for(auto &x: nums) left[x]++;
        
        for(auto &x: nums){
            //already a part of some sequence
            if(left[x] == 0) continue;
            
            //if there is a sequence before this number like for 3, if there is a seq that includes 2 then we will add 3 to that seq
            if(seq[x-1]>0){
                left[x]--;
                seq[x-1]--;
                seq[x]++;
            }
            else{
                //if there is no seq from prev number, we need to make a new seq from this number
                if(left[x+1] == 0 || left[x+2] == 0){
                    //if it is not possible to arrange 3 numbers
                    return false;
                }
                left[x]--;
                left[x+1]--;
                left[x+2]--;
                //indicate that there is a seq ending at x+2 number if some number needs it can be in the further iterations
                seq[x+2]++;
            }
        }
        return true;
    }
};