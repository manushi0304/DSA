class Solution {
public: 
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>> &grid, int i,int j, int &area){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1) return ;
        grid[i][j]=0;
        area++;
        for(int k=0;k<4;k++){
            int ii=i+dx[k], jj=j+dy[k];
            dfs(grid,ii,jj, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        for(int r=0;r<grid.size(); r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    int area=0;
                    dfs(grid,r,c,area);
                    maxarea=max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};