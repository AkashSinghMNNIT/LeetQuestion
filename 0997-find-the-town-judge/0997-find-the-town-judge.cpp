class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n+1], brr[n+1];
        fill(arr, arr+n+1, 0);
        fill(brr, brr+n+1, 0);
        for(auto it: trust)
        {
            arr[it[0]]++, brr[it[1]]++;
        }
        for(int i = 1; i<=n; ++i)
        {
            if(brr[i]==(n-1) && arr[i]==0) return i;
        }
        return -1;
    }
};