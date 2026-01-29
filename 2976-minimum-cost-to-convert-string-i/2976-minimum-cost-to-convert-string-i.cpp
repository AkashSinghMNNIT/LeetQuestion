class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int dist[26][26];
        fill(&dist[0][0], &dist[0][0] + 26*26, 1e8);
        int n = cost.size();
        long long ans = 0;
        for(int i = 0; i<26; ++i) dist[i][i] = 0;
        for(int i = 0; i<n; ++i)
        {
            int u = original[i]-'a', v = changed[i]-'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        for(int k = 0; k<26; ++k){
            for(int i = 0; i<26; ++i){
                for(int j = 0; j<26; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i = 0; i<source.size(); ++i)
        {
            int u = source[i]-'a', v = target[i]-'a';
            if(dist[u][v]==1e8) return -1;
            ans += dist[u][v];
        }
        return ans;
    }
};