class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,int node,int parent){
        vis[node]=1;
        for(auto it:adj[node]){
            if (!vis[it]) {
                if (dfs(adj, vis, it, node))
                    return true;
            }
            else if (it != parent) {
                return true; // cycle found
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        if(dfs(adj,vis,0,-1)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
