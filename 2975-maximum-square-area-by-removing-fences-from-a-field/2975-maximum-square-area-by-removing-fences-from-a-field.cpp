class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        sort(hf.begin(), hf.end());
        sort(vf.begin(), vf.end());
        unordered_set<int> h = {m-1}, v = {n-1};
        int ans = 0, mod = 1e9+7;
        for(int i = 0; i<hf.size(); ++i){
            h.insert(hf[i]-1);
            h.insert(m-hf[i]);
            for(int j = i+1; j<hf.size(); ++j){
                h.insert(hf[j]-hf[i]);
            }
        } 
        for(int i = 0; i<vf.size(); ++i){
            v.insert(vf[i]-1);
            v.insert(n-vf[i]);
            for(int j = i+1; j<vf.size(); ++j){
                v.insert(vf[j]-vf[i]);
            }
        } 
        for(auto it: v){
            if(h.find(it) != h.end()){
                ans = max(ans, it);
            }
        }
        if(ans == 0) return -1;
        return (ans*1ll*ans)%mod;
    }
};