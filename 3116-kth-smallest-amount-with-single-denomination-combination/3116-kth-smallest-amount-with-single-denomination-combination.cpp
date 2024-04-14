#define ll long long
class Solution {
public:
    bool pre(ll num, map<ll, vector<ll>> &mp, ll k)
    {
        ll ans = 0;
        for(auto [k, v]: mp)
        {
            for(auto it: v)
            {
                if(k & 1) ans += num/it;
                else ans -= num/it;
            }
        }
        return k<=ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        if(coins[0]==1) return k;
        vector<ll> v;
        for(int i = 0; i<coins.size(); ++i)
        {
            if(coins[i])
            for(int j = i+1; j<coins.size(); ++j)
            if(coins[j]%coins[i] == 0) coins[j] = 0;
        }
        for(auto it: coins) if(it) v.push_back(it);
        int n = v.size();
        map<ll, vector<ll>> mp;
        
        for(ll i = 1; i<(1<<n); ++i)
        {
            ll inc = __builtin_popcountll(i);
            ll lcm = 1, j = 0, mask = i;
            
            while(mask>0)
            {
                if(mask & 1) lcm = (lcm*v[j])/__gcd(lcm, v[j]);
                mask >>= 1, ++j;
            }
            mp[inc].push_back(lcm);
        }
        ll l = 1, h = 1e11;
        while(h-l>1)
        {
            ll mid = (h+l)/2;
            if(pre(mid, mp, k)) h = mid;
            else l = mid;
        }
        if(pre(l, mp, k)) return l;
        return h;
    }
};