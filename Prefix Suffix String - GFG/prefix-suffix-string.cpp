//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class trie{
    public:
    trie* child[26];
    bool isleaf;
    trie()
    {
        isleaf = 0;
        for(int i = 0 ; i<26; ++i) child[i] = NULL;
    }
};
    void add(string s, trie* root)
    {
        int n = s.length();
        for(int i = 0; i<n; ++i)
        {
            if(root->child[s[i] - 'a'] == NULL) root->child[s[i] - 'a'] = new trie();
            root = root->child[s[i] - 'a'];
        }
        root->isleaf = true;
    }
    
    bool ispresent(string t, trie* root)
    {
        int n = t.length();
        for(int i = 0; i<n; ++i)
        {
            if(root->child[t[i]-'a']) root = root->child[t[i] - 'a'];
            else return 0;
        }
        return 1;
    }

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        trie* pre = new trie();
        trie* suff = new trie();
        int ans = 0;
        for(auto &it: s1)
        {
            add(it, pre);
            string t = it;
            reverse(t.begin(), t.end());
            add(t, suff);
        }
        for(auto &it: s2)
        {
            string t = it;
            reverse(t.begin(), t.end());
            ans += (ispresent(it, pre) || ispresent(t, suff));
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends