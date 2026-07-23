class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=0) return dp[n];
        int oneStep=0;
        int twoStep=0;
        if(n>0){
        oneStep=solve(n-1,dp);
        twoStep=solve(n-2,dp);
        }
        return dp[n]=oneStep+twoStep;

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        return solve(n,dp);
    }
};
