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
    static bool cmp(const Interval& a, const Interval& b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<intervals.size()-1;i++){
            int currEnd=intervals[i].end;
            int nxtStrt=intervals[i+1].start;
            if(nxtStrt<currEnd) return false;
        }
        return true;
    }
};
