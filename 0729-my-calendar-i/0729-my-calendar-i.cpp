class MyCalendar {
private:
    map<int, int> mp;
public:
    MyCalendar() {
        mp[0] = -1;
    }
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        // ++it;
        if(it != mp.end() && it->second<end) return false;
        mp[end] = start;
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */