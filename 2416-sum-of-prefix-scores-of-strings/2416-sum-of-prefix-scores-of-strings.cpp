struct Node{
    vector<int> node;
    int leaf = 0;
    Node()
    {
        node.resize(26, -1);
    }
};
struct Trie{
    vector<Node> trie;
    Trie()
    {
        trie.emplace_back();
    }
    void add_string(string s)
    {
        int root = 0;
        for(auto c: s)
        {
            int index = c-'a';
            if(trie[root].node[index] == -1)
            {
                trie[root].node[index] = trie.size();
                trie.emplace_back();
            }
            root = trie[root].node[index];
            trie[root].leaf++;
        }
    }
    int score(string s)
    {
        int root = 0, ans = 0;
        for(auto it: s)
        {
            int index = it-'a';
            if(trie[root].node[index]==-1) return ans;
            root = trie[root].node[index];
            ans += trie[root].leaf;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n);
        Trie t;
        for(auto it: words) t.add_string(it);
        for(int i = 0; i<n; ++i) ans[i] = t.score(words[i]);
        return ans;
    }
};