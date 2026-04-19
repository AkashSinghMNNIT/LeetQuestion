class Solution {
    public int maxDistance(int[] a, int[] b) {
        int n = a.length, m = b.length, ans = 0, i = 0;
        for(int j = 0; j<m; ++j){
            while(i<n && i<=j && a[i]>b[j]) ++i;
            if(i<n && i<=j && a[i]<=b[j]) ans = Math.max(ans, j-i);
        }
        return ans;
    }
}