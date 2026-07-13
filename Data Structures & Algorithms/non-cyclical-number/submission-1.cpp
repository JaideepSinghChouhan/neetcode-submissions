class Solution {
public:
    int sumSq(int n){
        int ans=0;
        while(n>0){
            int r=n%10;
            ans+=r*r;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        do{
            st.insert(n);
            n=sumSq(n);
            if(n==1) return true;
        }
        while(st.find(n)==st.end());
    return false;
    }
};
