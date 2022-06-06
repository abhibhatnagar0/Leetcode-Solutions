class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix.size();
        int width = matrix[0].size();
        
        int first = 0, last = (length*width)-1;
        
        while(first<=last)
        {
            int mid = (first+last)/2;
            int i = mid/width, j = mid%width;
            if(matrix[i][j]<target)
            {
                first = mid+1;
            }
            else if(matrix[i][j]>target)
            {
                last = mid-1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};