/**
 * @param {number[]} nums
 * @return {number}
 */
var arraySign = function(nums) {
    return (nums.reduce((a, b) => a*b)>0?1:nums.reduce((a, b)=> a*b)<0?-1:0);
};