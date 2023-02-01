class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        int arr[n+1][m+1];
        arr[0][0] = 0;
        for(int i = 1; i<=n; ++i) arr[i][0] = i;
        for(int i = 1; i<=m; ++i) arr[0][i] = i;
        
        for(int i = 1; i<=n; ++i) // a
        {
            for(int j = 1; j<=m; ++j) // b
            {
                arr[i][j] = 1 + min(min(arr[i-1][j-1], arr[i][j-1]), arr[i-1][j]);
                if(a[i-1] == b[j-1]) arr[i][j] = min(arr[i][j], arr[i-1][j-1]);
            }
        }
        
        return arr[n][m];
    }
};