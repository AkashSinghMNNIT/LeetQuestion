class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int st, int en) {
       mp[st]++, mp[en]--;
        int sum = 0, ans = 0;
        for(auto [f, s]: mp) sum += s, ans = max(ans, sum);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */