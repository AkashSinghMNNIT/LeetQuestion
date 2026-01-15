class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hcon = 1, vcon = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for(int i = 1, cnt = 1; i<hBars.size(); ++i)
        {
            if(hBars[i]==hBars[i-1]+1)hcon = max(hcon, ++cnt);
            else cnt = 1;
        }
        for(int i = 1, cnt = 1; i<vBars.size(); ++i)
        {
            if(vBars[i]==vBars[i-1]+1)vcon = max(vcon, ++cnt);
            else cnt = 1;
        }
        return pow(min(hcon, vcon)+1, 2);
    }
};