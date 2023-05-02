/**
 * @param {number[]} nums
 * @return {number}
 */
var arraySign = function(nums) {
    let pro = 1;
    for(let n of nums)
        {
            if(n<0) pro *= -1;
            else if(n == 0) pro *= 0;
        }
    return pro;
};