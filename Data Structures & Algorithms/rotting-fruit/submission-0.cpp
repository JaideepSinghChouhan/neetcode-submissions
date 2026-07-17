class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int oranges=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                if(grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=1;
                }
                oranges++;
            }
        }
        int dx[]={0,-1,0,1};
        int dy[]={1,0,-1,0};
        int minutes=0,cnt=0;
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                auto it=q.front();
                q.pop();
                int x=it.first,y=it.second;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
            }
            if(!q.empty()) minutes++;
        }
        return cnt==oranges?minutes:-1;
    }
};