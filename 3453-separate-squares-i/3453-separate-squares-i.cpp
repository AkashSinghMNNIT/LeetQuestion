class Solution {
public:
    bool check(double ht, double req, vector<vector<int>>& sq){
        for(auto &it: sq)
        {
            double y = it[1], l = it[2];
            if(ht>=y)
            req -= min(ht-y, l)*1ll*l;
        }
        return req<=0;
    }
    double separateSquares(vector<vector<int>>& sq) {
        double req = 0, hi = 0, total = 0, lo = 0, rd = 1e-5;
        int n = sq.size();
        for(auto &it: sq)
        {
            double y = it[1], l = it[2];
            total += l*1ll*l;
            hi = max(hi, y+l);
        }
        while(abs(hi-lo)>rd){
            double mid = (hi+lo)/2;
            if(check(mid, total/2, sq)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};