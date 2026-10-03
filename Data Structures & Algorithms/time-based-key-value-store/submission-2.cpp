class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>timeMpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) { 
        if(timeMpp.find(key)==timeMpp.end()) return "";
        auto &v=timeMpp[key];
        int st=0;
        int end=v.size()-1;
        string ans="";
        while(st<=end){
            int mid=(st+end)/2;
            if(v[mid].first<=timestamp){
                ans=v[mid].second;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};
