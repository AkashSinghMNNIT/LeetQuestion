/**
 * @param {number[]} nums
 * @return {number}
 */

let countdig = function(n)
{
    let cnt = 0;
    while(parseInt(n))
        {
            ++cnt;
            n = parseInt(n)/10;
        }
    return cnt;
}

var findNumbers = function(nums) {
    let ans = 0;
    for(let n of nums)
        {
            console.log(countdig(n));
            ans += ((countdig(n)%2 == 0));
        }
    return ans;
};