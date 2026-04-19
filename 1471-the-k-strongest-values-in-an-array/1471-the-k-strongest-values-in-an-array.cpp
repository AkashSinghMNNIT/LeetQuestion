class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> q;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mid = arr[(n-1)/2];
        for(auto it: arr){
            q.push({abs(it-mid), it});
        }
        vector<int> ans;
        while(k--){
            auto top = q.top();
            q.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};