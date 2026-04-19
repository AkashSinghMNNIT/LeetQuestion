class Solution {
    private long dfs(int i, boolean[] vis, List<Integer>[] adj){
        if(vis[i]) return 0;
        vis[i] = true;
        long cnt = 1;
        for(int it: adj[i]){
            if(!vis[it])
            cnt += dfs(it, vis, adj);
        }
        return cnt;
    }
    public long countPairs(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        long ans = ((long)n*(n-1))/2;
        boolean[] vis = new boolean[n];
        Arrays.fill(vis, false);
        for(int i = 0; i<n; ++i){
            adj[i] = new ArrayList<>();
        }
        for(int[] it: edges){
            adj[it[0]].add(it[1]);
            adj[it[1]].add(it[0]);
        }
        for(int i = 0; i<n; ++i){
            if(!vis[i]){
                long cnt = dfs(i, vis, adj);
                ans -= ((long)cnt * (cnt-1))/2;
            }
        }
        return ans;
    }
}