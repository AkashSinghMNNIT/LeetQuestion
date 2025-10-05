class Solution {
public:
    using ll = long long;

    long long countNoZeroPairs(long long n) {
        string s = to_string(n);
        int len = s.length();
        reverse(s.begin(), s.end());
        ll ans = 0;
        for(int lena = 1; lena<=len; ++lena)
        {
            for(int lenb = 1; lenb<=len; ++lenb)
            {
                vector<vector<ll>> dp(len+1, vector<ll>(2, 0));
                dp[0][0] = 1;
                for(int pos = 0; pos<len; ++pos)
                {
                    int mina=pos<lena?1:0, maxa=pos<lena?9:0, minb=pos<lenb?1:0, maxb=pos<lenb?9:0;
                    for(int carry = 0; carry<=1; ++carry)
                    {
                        ll ways = dp[pos][carry];
                        if(!ways) continue;
                        for(int a=mina; a<=maxa; ++a)
                        {
                            for(int b=minb; b<=maxb; ++b)
                            {
                                int sum = a+b+carry;
                                if(sum%10 == (s[pos]-'0'))
                                {
                                    dp[pos+1][sum/10] += ways;
                                }
                            }
                        }
                    }
                }
                ans += dp[len][0];
            }
        }
        return ans;
    }
};