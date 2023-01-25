//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string l, u;
        for(auto it: s)
        {
            if(it>='a' && it<='z') l += it;
            else u += it;
        }
        sort(l.begin(), l.end());
        sort(u.begin(), u.end());
        int i = 0, j = 0, k = 0;
        while(i<n)
        {
            if(s[i]>='a' && s[i]<='z') s[i++] = l[j++];
            else s[i++] = u[k++];
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends