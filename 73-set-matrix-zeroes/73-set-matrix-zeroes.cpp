class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
          int n=matrix[0].size();
            //one way is making 2 vectors of row and column idxs which are to be made all 0
            //vector<int> row(m,1);
            // if row[i]==0, set matrix[i][j]=0 where j lies from 0 to n-1
            //for o(1) space, set 0 idx row and column of matrix as 2 vectors
            bool zero_in_first_row=false;
            bool zero_in_first_column=false;
            for(int i=0;i<m;i++){
                    if(matrix[i][0]==0) zero_in_first_column=true;
            }
             for(int j=0;j<n;j++){
                    if(matrix[0][j]==0) zero_in_first_row=true;
            }
         for(int i=1;i<m;i++){
                 for(int j=1;j<n;j++){
                       if(matrix[i][j]==0){
                               matrix[i][0]=0;
                               matrix[0][j]=0;
                       }    
              }
         }
         for(int i=1;i<m;i++){
                 if(matrix[i][0]==0) {
                         for(int j=1;j<n;j++)
                          matrix[i][j]=0; 
                 }
         }
             for(int j=1;j<n;j++){
                 if(matrix[0][j]==0) {
                         for(int i=1;i<m;i++)
                           matrix[i][j]=0; 
                 }
         }
         if(zero_in_first_column){
                 for(int i=0;i<m;i++)
                   matrix[i][0]=0;
         }  
          if(zero_in_first_row){
                 for(int j=0;j<n;j++)
                   matrix[0][j]=0;
         }  
            
            
    }
};