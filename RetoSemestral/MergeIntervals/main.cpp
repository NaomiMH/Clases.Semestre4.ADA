/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        for(int cont=0; cont<intervals.size()-1; cont++){
            if(intervals[cont].end>=intervals[cont+1].start){
                if(intervals[cont].start<=intervals[cont+1].end){
                    intervals[cont].end=max(intervals[cont+1].end,intervals[cont].end);
                    intervals[cont].start=min(intervals[cont].start,intervals[cont+1].start);
                    intervals.erase(intervals.begin()+cont+1);
                    cont=-1;
                }
                else{
                    intervals.push_back(intervals[cont]);
                    intervals.erase(intervals.begin()+cont);
                    cont=-1;
                }
            }
        }
        return intervals;
    }
};
