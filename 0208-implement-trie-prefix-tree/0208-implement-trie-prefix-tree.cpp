
class Tri{
    public:
    
    Tri* v[26];
    bool end = false;
    Tri()
    {
        for(int i = 0; i<26; ++i) v[i] = NULL;
    }
};

class Trie {
public:
    // Trie* v[26];
    // bool end = 0;
    Tri* t;
    Trie() {
        // fill(v, v+26, NULL);
        t = new Tri();
    }
    
    void insert(string word) {
        int n = word.length();
        Tri* curr = t;
        for(int i = 0; i<n; ++i)
        {
            if(curr->v[word[i]-'a'] == NULL) curr->v[word[i]-'a'] = new Tri();
            curr = curr->v[word[i]-'a'];
        }
        curr->end = 1;
    }
    
    bool search(string word) {
        int n = word.length();
        Tri* curr = t;
        for(int i = 0; i<n; ++i)
        {
            if(curr->v[word[i]-'a'] == NULL) return 0;
            curr = curr->v[word[i]-'a'];
        }
        return curr->end;
    }
    
    bool startsWith(string word) {
        int n = word.length();
        Tri* curr = t;
        for(int i = 0; i<n; ++i)
        {
            if(curr->v[word[i]-'a'] == NULL) return 0;
            curr = curr->v[word[i]-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */