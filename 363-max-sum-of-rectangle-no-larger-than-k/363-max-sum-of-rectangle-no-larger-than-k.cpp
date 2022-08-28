class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int t) {
         int res = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        // prefix sum of every row
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        for(int c1=0; c1<m; c1++){
            for(int c2=c1; c2<m; c2++){
                //fixed 2 columns
                //find maximum sum subarray with sum<=k 
                set<int>s = {0};
                int sum = 0;
                for(int k=0; k<n; k++){
                    sum += matrix[k][c2];
                    if(c1>0) sum-= matrix[k][c1-1];
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