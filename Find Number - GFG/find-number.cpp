//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        long long ans = 0;
        int arr[5] = { 1, 3, 5, 7, 9};
        string s;
        long long t = n;
        while(t)
        {
            long long rem = t%5;
            if(rem)
            {
                s += ('0' + rem);
                t /= 5;
            }
            else
            {
                s += '5';
                t /= 5, --t;
            }
        }
        // cout<<s<<endl;
        for(int i = 0; i<s.length(); ++i)
        {
            ans += pow(10, i) * arr[(s[i]-'0'-1)%5];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends