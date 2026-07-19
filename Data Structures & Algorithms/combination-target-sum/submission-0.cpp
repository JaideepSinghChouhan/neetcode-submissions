class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&res,vector<int>&temp,int target,int ind){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(ind<0 || target<0){
            return ;
        }

        solve(nums,res,temp,target,ind-1);
        temp.push_back(nums[ind]);
        solve(nums,res,temp,target-nums[ind],ind);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n=nums.size();
        solve(nums,res,temp,target,n-1);
        return res;
    }
};
