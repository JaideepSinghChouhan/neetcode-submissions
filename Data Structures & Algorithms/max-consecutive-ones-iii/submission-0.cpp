class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int res=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                k--;
            }
            while(k<0){
                k+=(nums[l]==0)?1:0;
                ++l;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};