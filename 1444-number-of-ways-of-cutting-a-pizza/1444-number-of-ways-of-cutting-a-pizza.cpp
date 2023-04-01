class Solution
{
    public:
    long long inf = 1e9+7;
    int dp[51][51][11];
    
    long long bin(long long a, long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b & 1) ans = (ans * a)%inf;
            a = (a * a)%inf;
            b >>= 1;
        }
        return ans;
    }
    
        long long fun(int i, int j, int k, vector<string> &p)
        {
            int n = size(p), m = size(p[0]);
            if(k<0) return 0;
            if (k == 0)
            {
                return (i == n || j == m);
            }
            if (i >= n || j >= m) return 0;
            if(dp[i][j][k] !=-1) return dp[i][j][k];
            
            int row = i - 1, col = j - 1;
            long long ans = 0;

           	// horizontally
            for (int r = i; r < n && row == i - 1; ++r)
            {
                for (int c = j; c < m; ++c)
                {
                    if (p[r][c] == 'A')
                    {
                        row = r;
                        break;
                    }
                }
            }
            if (row >= i)
            {
                for (; row < n; ++row) ans = (ans + fun(row + 1, j, k - 1, p))%inf;
            }

           	// veritcally

            for (int c = j; c < m && col==j-1; ++c)
            {
                for (int r = i; r < n; ++r)
                {
                    if (p[r][c] == 'A')
                    {
                        col = c;
                        break;
                    }
                }
            }
            if (col >= j)
            {
                for (; col < m; ++col) ans = (ans + fun(i, col+1, k - 1, p))%inf;
            }
            return dp[i][j][k] = ans;
        }

    int ways(vector<string> &p, int k)
    {
        int n = size(p), m = size(p[0]);
        memset(dp, -1 ,sizeof(dp));
        

        return (fun(0, 0, k, p)*bin(2, inf-2))%inf;
    }
};