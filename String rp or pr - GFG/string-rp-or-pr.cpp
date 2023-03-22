//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long solve(int x,int y,string s){
      char a = 'r', b = 'p';
      if(x>=y) a = 'p', b = 'r';
      else swap(x, y);
      long long ans = 0, n = s.length();
      stack<char> st;
      
      for(int i = 0; i<=n; ++i)
      {
          if(i<n && s[i] == a) st.push(a);
          else if(s[i] == b)
          {
              if(i<n && (st.empty() || st.top()==b)) st.push(b);
              else ans += 0ll + x, st.pop();
          }
          else
          {
              int c = 0, d = 0;
              while(!st.empty())
              {
                  if(st.top()==a) ++d;
                  else ++c;
                  st.pop();
              }
              ans += y*1ll*(min(c, d));
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends