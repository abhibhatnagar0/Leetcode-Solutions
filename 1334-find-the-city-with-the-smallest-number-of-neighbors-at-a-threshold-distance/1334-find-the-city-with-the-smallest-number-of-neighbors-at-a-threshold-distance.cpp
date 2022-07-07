class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>> matrix(n, vector(n, 10001));
        //wt can go upto 10^4....so 10001 can be taken as INT_MAX
        for(auto edge:edges)
            matrix[edge[0]][edge[1]]=matrix[edge[1]][edge[0]]=edge[2];
        for(int i=0; i<n; i++)
            matrix[i][i]=0;
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][k]!=10001 && matrix[k][j]!=10001)
                  matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        //res gives node who has min no of paths from all other nodes with atmost dis threshold
        int res=0,curr_min=INT_MAX;
                
         for(int i=0; i<n; i++)
         {
             int ctr=0; //for ith node, dis of others less than threshold
             for(int j=0; j<n; j++)
                 if(matrix[i][j]<=distanceThreshold)
                     ctr++;
             if(ctr<=curr_min)
             {
                 curr_min=ctr;
                 res=i;
             }
         }
        
        return res;
        
    }
};