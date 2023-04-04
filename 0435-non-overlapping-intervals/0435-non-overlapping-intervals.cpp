class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            return (a[1] == b[1] ? a[0]<b[0]: a[1]<b[1]);
        }
    int eraseOverlapIntervals(vector<vector < int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int temp = 1, l = intervals[0][1], n = intervals.size();
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= l)
            {
                temp++;
                l = intervals[i][1];
            }
        }
        return (n - temp);
    }
};