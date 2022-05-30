class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int idx, int k,vector<int>&current,int n)
    {// will include idx and call recursion to give remaining k-1 numbers from idx+1 to n
     //initially idx=1, n=4 k=2
            //total combinations = 4c2=6
            //all iterations will give 1,2  1,3  1,4
            //then idx=2, all iterations give 2,3  2,4 
            //idx=3........  3,4
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<n+1;i++) 
        {
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        helper(1,k,current,n);
        return ans; //return answer
    }
};