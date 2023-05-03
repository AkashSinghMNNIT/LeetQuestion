/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    let a=[];
    for(let n of nums)
        {
            a.push(n*n);
        }
    a.sort((a, b)=> a-b);
    return a;
};