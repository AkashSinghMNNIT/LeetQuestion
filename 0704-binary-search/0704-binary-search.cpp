class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int low = 0,mid,up = nums.size() - 1;
        
        while(low<=up)
        {
            
            mid = (low + up)/2;
            if(target > nums[mid])
                low = mid + 1;
            else if(target < nums[mid])
                up = mid -1;
            else
                return mid;
        }
        return -1;
    }
};