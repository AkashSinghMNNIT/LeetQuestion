class Solution {
public:
    vector <int> arr;
    vector <int> temp;
    
    void merge(int l, int mid, int r){
        int n = arr.size();
        int i=l;
        int j=mid+1;
        int k=l;
        while(i<=mid && j<=r){
            if(arr[i]<arr[j]) temp[k++]=arr[i++];
            else temp[k++]=arr[j++];
        }
        while(i<=mid) temp[k++]=arr[i++];
        while(j<=r) temp[k++]=arr[j++];
        for(int k=l; k<=r; k++){
            arr[k] = temp[k];
        }
    }
    
    void mergesort(int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergesort(l, mid);
            mergesort(mid+1, r);
            merge(l, mid, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        arr = nums;
        temp = nums;
        mergesort(0, nums.size()-1);
        return arr;
    }
};