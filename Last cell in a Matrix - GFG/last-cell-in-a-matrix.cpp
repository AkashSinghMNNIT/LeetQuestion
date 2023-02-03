//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mat, int r, int c){
        int i, j, h = 1, v;
        i = j = v = 0;
        
        while(i>=0 && j>=0 && i<r && j<c)
        {
            if(mat[i][j]!=0)
            {
                mat[i][j] = 0;
                if(h) v = h, h = 0;
                else h = -v, v = 0;
            }
                i+=v, j += h;
        }
        i = min(i, r-1), i = max(i, 0);
        j = min(j, c-1), j = max(j, 0);
        return {i, j};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends