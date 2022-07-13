class Solution {
public:
     int paths=0;
    void dfs(vector<vector<int>>& grid, int x, int y, int count, int &zeros) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
        
        if (grid[x][y] == 2) {
            if(zeros == count) paths++; 
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid, x+1, y, count+1,zeros);
        dfs(grid, x-1, y, count+1,zeros);
        dfs(grid, x, y+1, count+1,zeros);
        dfs(grid, x, y-1, count+1,zeros);
        
        grid[x][y] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x, start_y;
        int zeros=1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) start_x = i, start_y = j;
                else if (grid[i][j] == 0) zeros++;
            }
        }
        int count=0;
       
        dfs(grid, start_x, start_y, count,zeros);
     
        return paths;
    }
    

};