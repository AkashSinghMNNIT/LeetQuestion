//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        int arr[26] = {0};
        
        for(auto it: a) arr[tolower(it)-'a']++;
        for(auto it: b) {
            arr[tolower(it)-'a']--;
        }
        for(int i = 0; i<26; ++i) if(arr[i]) return -1;
        int n = a.length(), i , j, ans = 0;
        i = j = n-1;
        while(i>=0)
        {
            if(a[i] == b[j]) --j, --i;
            else --i, ++ans;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends