//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int>q;
        vector<int>v;
        for(int i=0;i<k;i++)
        {
            if(q.empty())q.push_back(i);
            else
            {
                while(q.size()>0 && arr[q.back()]<=arr[i])q.pop_back();
                q.push_back(i);
            }
        }
        v.push_back(arr[q.front()]);
        for(int i=k;i<n;i++)
        {
            while(q.size()>0 && q.front()<=i-k)q.pop_front();
            if(q.size()==0)q.push_back(i);
            else
            {
                while(q.size()>0 && arr[q.back()]<=arr[i])q.pop_back();
                q.push_back(i);
            }
            v.push_back(arr[q.front()]);
        }
        return v;
        
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends