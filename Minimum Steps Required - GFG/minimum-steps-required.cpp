//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int n = str.length(), a = str[0]=='a', b = str[0]=='b';
    for(int i = 1; i<n; ++i)
    {
        a += (str[i]=='a' && str[i-1]=='b');
        b += (str[i]=='b' && str[i-1]=='a');
    }
    return 1 + min(a, b);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends