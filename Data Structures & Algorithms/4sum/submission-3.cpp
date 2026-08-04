class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n=nums.size();
       vector<vector<int>>ans;
       set<vector<int>>st;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    st.insert({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                }
                if(sum>target){
                    l--;
                }
                if(sum<target){
                    k++;
                }
              }
           }
       }
       for(auto it:st){
        ans.push_back(it);
       }
       return ans;
    }
};