class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int t) {
         int res = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int c1=0; c1<m; c1++){
            vector<int>temp(n);// stores prefix sum of all rows from [c1,c2]
            for(int c2=c1; c2<m; c2++){
                //fixed 2 columns
                for(int k=0; k<n; k++){
                    temp[k] += matrix[k][c2];
                }
                //find maximum sum subarray in temp with sum<=k 
                set<int>s = {0};//stores prefix sum of temp
                int sum = 0;
                for(auto p: temp){
                    sum += p;
                    auto it = s.lower_bound(sum-t); //gives iterator of sum eq to or just greater than (sum-t)
                    if(it != s.end()){
                        res = max(res,sum-*it);//res has sum eq to or just less than t
                    }
                    s.insert(sum);
                }
            }
        }
        return res;
    }
};