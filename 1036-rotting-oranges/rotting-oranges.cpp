class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1}; 
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        queue<pair<int, int>>pq;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    pq.push({i,j});
                }
            }
        }
        while(!pq.empty()){
            int sz=pq.size();
            int temp=0;
            while(sz--){
                auto p=pq.front();
                pq.pop();
                for(int k=0;k<4;k++){
                    int i=p.first+dx[k], j=p.second+dy[k];
                    if(i>=0 && j>=0 && i<r && j<c && grid[i][j]==1){
                        grid[i][j]=2;
                        temp=1;
                        pq.push({i,j});
                    }
                }
            }
            ans+=temp;
        }
        for(auto v:grid){
            for(int x:v) if(x==1) return -1;

        }
        return ans;
    }
};