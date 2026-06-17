class Solution {
public:
    string topo(vector<vector<int>>& adj,vector<int>&present){
        vector<int>indegree(26,0);
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(indegree[i]==0 && present[i]){
                q.push(i);
            }
        }
        string ans="";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans+=(char)(node + 'a');

            for(auto it :  adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        int countPresent=0;
        for(int i=0;i<26;i++){
            if(present[i]) countPresent++;
        }
        if(ans.size()!=countPresent) return "";
        return ans;
    }

    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<int>present(26,0);
        for(auto &word:words){
            for(char c : word){
                present[c-'a']=1;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];

            int len=min(s1.size(),s2.size());
            
            int j;
            for(j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }

            if(j==len && s1.size()>s2.size()) return "";
        }
        return topo(adj,present);
    }
};
