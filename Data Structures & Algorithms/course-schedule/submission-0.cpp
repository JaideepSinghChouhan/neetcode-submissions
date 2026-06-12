class Solution {
public:
    bool dfs(vector<vector<int>>&adj,int node,vector<int>&vis,vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,it,vis,pathVis)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<m;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0),pathVis(numCourses,0);
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(dfs(adj,i,vis,pathVis)) return false;
            }
        }
        return true;
    }
};