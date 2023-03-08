#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll hi = (*max_element(begin(piles), end(piles))) + 1, l = 0;
        // hi = 12;
        
        auto pre = [&](ll hour)
        {
            ll ans = 0;
            for(auto it: piles) ans += (it/hour + (it%hour > 0));
            return ans <= h;
            cout<<h<<endl;
        };
        
        while((hi-l)>1)
        {
            ll mid = (hi + l)/2;
            if(pre(mid)) hi = mid;
            else l = mid;
        }
        return hi;
    }
};