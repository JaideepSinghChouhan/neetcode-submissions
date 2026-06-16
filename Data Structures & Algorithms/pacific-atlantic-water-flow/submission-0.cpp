class Solution {
public:
    vector<int>dr={0,0,1,-1};
    vector<int>dc={1,-1,0,0};
    void dfs(vector<vector<int>>&heights,vector<vector<int>>&vis,int r,int c,int n,int m){
        if(vis[r][c]) return;
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(heights,vis,nr,nc,n,m);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>atl(n,vector<int>(m,0));
        vector<vector<int>>pac(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dfs(heights,pac,i,0,n,m);
            dfs(heights,atl,i,m-1,n,m);
        }
        for(int i=0;i<m;i++){
            dfs(heights,pac,0,i,n,m);
            dfs(heights,atl,n-1,i,n,m);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j]==1 && pac[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};