//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p) {
        bool hsh[n];
        fill(hsh, hsh+n, 0);
        
        int ans = 0, cnt = 0;
        for(int i = 0; i<n-1; ++i) hsh[i] = s[i]==s[i+1], cnt += s[i]==s[i+1];
        // for(int i = 0; i<n; ++i) cout<<hsh[i]<<" ";
        for(auto it: p)
        {
            if(cnt <= 0) return ans;
            ++ans;
            if(hsh[it])
            {
                hsh[it] = 0;
                --cnt;
            }
            if(it) cnt -= hsh[it-1], hsh[it-1] = 0;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends