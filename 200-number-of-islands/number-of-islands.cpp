class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') 
            return;
        
        grid[i][j] = '2'; // mark as visited

        for(int k = 0; k < 4; k++){
            int ii = i + dx[k], jj = j + dy[k];
            dfs(grid, ii, jj);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }        
        return cnt;
    }
};
