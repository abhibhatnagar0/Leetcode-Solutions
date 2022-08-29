class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int m= grid2.size();
        int n=grid2[0].size();
        int cnt=0;
        bool isSubisland=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                   if(grid2[i][j]==1 && grid1[i][j]==1){
                       isSubisland=true;
                       dfs(grid1,grid2,i,j,m,n,isSubisland);
                       if(isSubisland) cnt++;                   
                   }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j,int m, int n, bool &isSubisland){
        if(i<0 || i>=m || j<0 ||j>=n) return;
        if(grid2[i][j]==0) return;
        //if(isSubisland==false) return;
        if(grid2[i][j]==1 && grid1[i][j]==0){
            isSubisland=false;
            return;
        }
        if(grid2[i][j]==1 && grid1[i][j]==1){
        grid2[i][j]=0;//making it visited, if it is not
        dfs(grid1,grid2,i+1,j,m,n,isSubisland);
        dfs(grid1,grid2,i-1,j,m,n,isSubisland);
        dfs(grid1,grid2,i,j-1,m,n,isSubisland);
        dfs(grid1,grid2,i,j+1,m,n,isSubisland);
        }
    }
};