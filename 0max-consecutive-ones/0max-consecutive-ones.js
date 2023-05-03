/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let ans = 0, i = 0, j = nums.length;
    while(i<nums.length)
        {
            if(nums[i]==0) ans = Math.max(ans, i-j), j = nums.length;
            else if(j == nums.length) j = i;
            ++i;
        }
    ans = Math.max(ans, i-j);
    return ans;
};