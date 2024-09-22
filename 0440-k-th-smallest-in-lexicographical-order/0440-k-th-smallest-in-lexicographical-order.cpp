class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        --k;
        while(k > 0)
        {
            int steps = countsteps(n, curr, curr+1);
            if(steps <= k) ++curr, k -= steps;
            else 
            {
                --k;
                curr *= 10;
            }
        }
        return curr;
    }
private: 
    int countsteps(int n, long start, long end)
    {
        int steps = 0;
        while(start <= n)
        {
            steps += min(end, (long)n+1) - start;
            start *= 10, end *= 10;
        }
        return steps;
    }
};