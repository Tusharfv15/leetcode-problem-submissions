class MyCalendar {
public:
map<int,int>intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto nextTime = intervals.lower_bound(start);

        if(nextTime != intervals.end() && nextTime->first < end)return false;;
        if(nextTime != intervals.begin() && prev(nextTime)->second > start) return false;

        intervals[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */