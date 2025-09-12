class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        for(auto it: s) vowelCount += (st.find(it) != st.end());
        if(!vowelCount) return 0;
        return 1;
    }
};