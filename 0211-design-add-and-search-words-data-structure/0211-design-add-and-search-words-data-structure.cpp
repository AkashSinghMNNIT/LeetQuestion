class Trie{
    public:
    vector<Trie*> t;
    bool end = 0;
    Trie()
    {
        t.resize(27);
        // fill(t.begin(), t.end(), NULL);
        for(int i = 0; i<27; ++i) t[i] = NULL;
    }
};

class WordDictionary {
public:
    Trie *root ;
    unordered_map<char, int> mp;
    WordDictionary() {
        root = new Trie();
        for(int i = 0; i<26; ++i)
        {
            mp['a'+i] = i;
        }
        mp['.'] = 26;
    }
    
    void addWord(string s) {
        int n = s.length();
        Trie *curr = root;
        for(int i = 0; i<n; ++i)
        {
            if(!curr->t[mp[s[i]]]) curr->t[mp[s[i]]] = new Trie();
            curr = curr->t[mp[s[i]]];
        }
        curr->end = 1;
    }
    bool dfs(Trie* root, string &s, int idx)
    {
        int n = s.length();
        if(!root) return 0;
        if(idx == n) return root->end;
        if(s[idx] != '.') return dfs(root->t[s[idx]-'a'], s, idx+1);
        else
        {
            for(int i = 0; i<26; ++i)
            {
                if((root->t[i]) && dfs(root->t[i], s, idx+1)) return 1;
            }
            return 0;
        }
    }
    bool search(string s) {
        int n = s.length();
        return dfs(root, s, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */