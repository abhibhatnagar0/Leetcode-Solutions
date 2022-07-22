class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        if(n<=2) return 0;
        
        int maxLen = 0; 
        for(int i=1; i<=n-2; i++) 
        { //find peak val (greater than both neighbours)
            if(A[i] > A[i+1] && A[i] > A[i-1])
            {
                int left = i-1;
                int right = i+1;
                
                while(left > 0 && A[left-1] < A[left]) left--;
                while(right < n-1 && A[right+1] < A[right]) right++;
                //left and right are 2 dips
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};