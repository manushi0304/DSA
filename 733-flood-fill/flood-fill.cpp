class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1, 0,1};
    int r, c;
    void dfs(int i, int j, int ini_color, int color, vector<vector<int>>& img ){
        if(i<0 or j<0 or j>=c or i>=r or img[i][j]!=ini_color) return;
        img[i][j]=color;
        for(int k=0;k<4;k++){
            int ii=i+dx[k];
            int jj=j+dy[k];

            dfs(ii,jj, ini_color, color, img);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r=image.size();
        c=image[0].size();
        int ini_color=image[sr][sc];
        if(ini_color==color) return image;

        dfs(sr,sc,ini_color, color, image);
        return image;
    }
};