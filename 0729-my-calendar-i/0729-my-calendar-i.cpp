class MyCalendar {
    map<int, int> intervals; 
public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto next = intervals.lower_bound(start); 
        if (next != intervals.end() && next->first < end) {
            return false; // Overlaps with next interval
        }
        if (next != intervals.begin() && prev(next)->second > start) {
            return false; // Overlaps with previous interval
        }
        intervals[start] = end; // No overlap, add interval
        return true;
    }
};
