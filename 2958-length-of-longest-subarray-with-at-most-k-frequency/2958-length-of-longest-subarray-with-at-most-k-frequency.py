class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = {}
        j, ans = 0, 0
        for i in range(len(nums)):
            mp[nums[i]] = mp.get(nums[i], 0) + 1
            while mp[nums[i]] > k:
                mp[nums[j]] -= 1
                j += 1
            ans = max(ans, i-j+1)
        return ans
