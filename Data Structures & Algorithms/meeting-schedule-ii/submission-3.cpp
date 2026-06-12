/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start,end;
        for(auto it:intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int s=0,e=0;
        int cnt=0,res=0;
        int n=start.size();
        while(s<n && e<n){
            if(start[s]<end[e]){
                s++;
                cnt++;
            }
            else{
                e++;
                cnt--;
            }
            res=max(cnt,res);
            }
        return res;
    }
};
