class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int>&vis,int node){
        if(vis[node]) return;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ans++;
            }
        }
        return ans;
    }
};
