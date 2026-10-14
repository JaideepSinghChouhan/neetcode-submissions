class Solution {
public:
    int dfs(vector<int>&newNums,int l,int r,vector<vector<int>>&dp){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        for(int i=l;i<=r;i++){
            int coins=newNums[l-1]*newNums[i]*newNums[r+1];
            coins+=dfs(newNums,l,i-1,dp)+dfs(newNums,i+1,r,dp);
            dp[l][r]=max(dp[l][r],coins);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>newNums(n+2,1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        for(int i=0;i<n;i++){
            newNums[i+1]=nums[i];
        }
        return dfs(newNums,1,newNums.size()-2,dp);
    }
};
