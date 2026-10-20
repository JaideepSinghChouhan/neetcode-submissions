class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastEnd;
        for(int i=0;i<s.size();i++){
            lastEnd[s[i]]=i;
        }
        int start=0,end=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            end=max(end,lastEnd[s[i]]);
            if(i==end){
                ans.push_back(i-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};
