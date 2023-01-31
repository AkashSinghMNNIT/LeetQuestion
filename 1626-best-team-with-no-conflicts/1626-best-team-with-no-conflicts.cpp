class Solution
{
    public:
        int bestTeamScore(vector<int> &scores, vector<int> &ages)
        {
            int mxage = 0, n = scores.size(), ans = 0;
            vector<vector < int>> arr(n, vector<int> (2));

            for (int i = 0; i < n; ++i) arr[i][0] = scores[i], arr[i][1] = ages[i], mxage = max(mxage, ages[i]);
            sort(arr.begin(), arr.end());
            int sc[mxage + 1];
            fill(sc, sc + mxage + 1, 0);

            for (int i = 0; i < n; ++i)
            {
                sc[arr[i][1]] = max(sc[arr[i][1]], arr[i][0] + query(sc, arr[i][1], mxage));
                update(sc, arr[i][1], mxage);
                ans = max(ans, sc[arr[i][1]]);
            }
            return ans;
        }

    int query(int sc[], int age, int mxage)
    {
        int currbest = 0;
        for (int i = age; i > 0; i -= i &(-i))
        {
            currbest = max(sc[i], currbest);
        }
        return currbest;
    }

    void update(int sc[], int age, int mxage)
    {
        int currbest = sc[age];
        for (int i = age; i <= mxage; i += i &(-i))
        {
            sc[i] = max(sc[i], currbest);
        }
    }
};