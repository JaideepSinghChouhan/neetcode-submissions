class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<int>&chosen,vector<vector<int>>&res){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!chosen[i]){
                temp.push_back(nums[i]);
                chosen[i]=1;
                solve(nums,temp,chosen,res);
                temp.pop_back();
                chosen[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        vector<int>chosen(n,0);
        vector<int>temp;
        solve(nums,temp,chosen,res);
        return res;

    }
};
