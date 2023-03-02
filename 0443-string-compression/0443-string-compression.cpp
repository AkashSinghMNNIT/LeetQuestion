class Solution {
public:
    
    int fun(int n)
    {
        int ans = 0;
        while(n) ++ans, n/=10;
        return ans;
    }
    
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, j = 0, k = 0;
        
        while(j<=n)
        {
            if(j<n && chars[i]==chars[j]) ++j;
            else
            {
                if(j-i == 1) chars[k++] = chars[i];
                else 
                {
                    chars[k++] = chars[i];
                    int x = j-i, cnt = fun(x), c = cnt;
                    while(cnt--)
                    {
                        chars[k+cnt] = (x%10 + '0');
                        x/=10;
                    }
                    k += c;
                }
                i = j++;
            }
        }
        return k;
        
        
    }
};