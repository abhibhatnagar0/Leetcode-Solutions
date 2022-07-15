class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int num, int k,vector<int>&current,int n)
    {// will include num and call recursion to give remaining k-1 numbers from num+1 to n
     //initially num=1, n=4 k=2
            //total combinations = 4c2=6
            //all iterations will give 1,2  1,3  1,4
            //then num=2, all iterations give 2,3  2,4 
            //num=3........  3,4
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=num;i<n+1;i++) 
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