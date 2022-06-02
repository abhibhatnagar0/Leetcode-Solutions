class Solution {
public:
    int uniquePaths(int m, int n) {
        //m-1 times down jana hai
        //n-1 times right jana hai 
       /* _ _ _ _ _ _ _ _ total m+n-2 spaces
       to be filled with R and D
       total ways to fill R = (m+n-2)C m-1 or (m+n-2)C n-1 */
            int N = m+n-2;
            int r = m-1;
            double ans=1;
            for(int p=1;p<=r;p++){
                   ans=ans * (N-r+p)/p; 
            }
            return ans;
    }
};