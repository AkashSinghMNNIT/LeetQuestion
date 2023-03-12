//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> arr, int N) {

        //code here

        int i=0;

        int j=N-1;

        int max=0;

        vector<int> ans;

        ans.push_back(0);

         ans.push_back(0);

        int count=0;

        while(i<N && j >=0){

            if(arr[i][j]!=1){

                i++;

            }

            else{

                j--;

                count++;

            }

            if(count>max){

                max=count;

                ans.pop_back();

                ans.pop_back();

                ans.push_back(i);

                ans.push_back(count);

                

            }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends