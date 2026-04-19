class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<pair<int, int>> v;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mid = arr[(n-1)/2];
        for(auto it: arr){
            v.push_back({abs(it-mid), it});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = n-1; i>n-1-k; --i){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};