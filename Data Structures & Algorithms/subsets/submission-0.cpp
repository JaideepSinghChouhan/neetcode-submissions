class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&res,vector<int>&temp,int ind){
        if(ind<0){
            res.push_back(temp);
            return;
        }
        solve(nums,res,temp,ind-1);
        temp.push_back(nums[ind]);
        solve(nums,res,temp,ind-1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>temp;
        solve(nums,res,temp,n-1);
        return res;
    }
};
