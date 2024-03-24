class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        mod = 100001
        for i in range(len(nums)):
            ind = nums[i]%mod
            if int(nums[ind]/mod) > 0:
                return nums[i]%mod
            nums[ind] += mod
        return -1
