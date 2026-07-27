class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),node=0;
        vector<int>dist(n,100000000);
        vector<bool>visit(n,false);
        int edges=0,res=0;

        while(edges<n-1){
            visit[node]=true;
            int nxtNode=-1;
            for(int i=0;i<n;i++){
                if(visit[i]) continue;
                int curDist=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
                dist[i]=min(dist[i],curDist);
                if(nxtNode==-1 || dist[i]<dist[nxtNode]){
                    nxtNode=i;
                }
            }
            res+=dist[nxtNode];
            node=nxtNode;
            edges++;
        }
        return res;
    }
};
