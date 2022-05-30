class Solution {
public:
        vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
         vector<int> subSet;
    
    help(1, n, k, subSet);
    return ans;
    }
        
    void help(int i, int n, int k, vector<int> &subSet)
{
    if (k == 0) //k stores remaining no of ele
    {
        ans.push_back(subSet);
        return;
    }
    //har i pe jakr decision lenge ki usko lena h ki nhi
    if (k > n - i + 1)// if at i, and i-1 me se kisi ko nhi lia ho,then k=n-(i-1)
        return; //but if remaining ele zaada h, ie aage ke sbko lekr bhi k nhi aa layenge toh just return
    if (i > n)
        return; //as i can go from 1 to n
            
            // take the ith ele
    subSet.push_back(i);
    help(i + 1, n, k - 1, subSet); //i ko subset me le lia, ab k-1 aur chahiye
    subSet.pop_back();
            // skip the ith ele
    help(i + 1, n, k, subSet);  //i+1 ke aage se k chahiye
}
};