class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        int n = nums.size();
        int arr[1001] = {0};
        for(int i = 2; i<=1000; ++i) 
        {
            if(arr[i]==0)
            {
                prime.push_back(i);
                for(int j = i*i; j<=1000; j += i) arr[j] = 1;
            }
        }
        for(int i = n-2; i>=0; --i)
        {
            if(nums[i]>=nums[i+1])
            {
                int index = upper_bound(prime.begin(), prime.end(), nums[i]-nums[i+1]) - prime.begin();
                if(index == prime.size() || prime[index]>=nums[i]) return 0;
                nums[i] -= prime[index];
            }
        }
        return 1;
    }
};