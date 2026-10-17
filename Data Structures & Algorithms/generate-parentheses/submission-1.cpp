class Solution {
public:
    void solve(vector<string>& ans,string temp,int open,int close){
       if(open==0 && close==0){
        ans.push_back(temp);
        return;
       }
       else if(open==close){
         temp+='(';
         solve(ans,temp,open-1,close);
       }
       else if(open==0){
        temp+=')';
        solve(ans,temp,open,close-1);
       }
       else if(close==0){
        temp+='(';
        solve(ans,temp,open-1,close);
       }
       else{
        temp+='(';
        solve(ans,temp,open-1,close);
        temp.pop_back();
        temp+=')';
        solve(ans,temp,open,close-1);
       }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(ans,temp,n,n);
        return ans;
    }
};
