
#define ll long long
class Solution
{
    public:

        bool pre(ll mid, vector<int> a)
        {
            ll n = size(a), sum = 0;
            for(auto it: a)
            {
                if(it > mid) 
                {
                    int c = it-mid;
                    if(c > sum) return 0;
                    else sum -= c;
                }
                else sum += mid-it;
            }
            return 1;
        }

    int minimizeArrayValue(vector<int> &nums)
    {
        ll n = size(nums);
        ll l = -1, h = *max_element(begin(nums), end(nums)) + 1;

        while (h - l > 1)
        {
            ll mid = l + (h - l) / 2;
            if (pre(mid, nums)) h = mid;
            else l = mid;
        }
        return h;
    }
};