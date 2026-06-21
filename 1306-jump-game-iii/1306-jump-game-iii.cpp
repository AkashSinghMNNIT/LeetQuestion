class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int top = q.front();
            if(arr[top]==0) return 1;
            q.pop();
            int left = top-arr[top], right = top+arr[top];
            if(left>=0 && !vis[left]) {
                q.push(left);
                vis[left] = 1;
            }
            if(right<n && !vis[right]) {
                q.push(right);
                vis[right] = 1;
            }
        }
        return 0;
    }
};