/**
 * @param {number[]} salary
 * @return {number}
 */
var average = function(salary) {
    var low = salary[0], high = salary[0], tot = 0;
    for(var sal of salary)
        {
            low = Math.min(low, sal);
            high = Math.max(high, sal);
            tot += sal;
        }
    return (tot - low - high)/(salary.length - 2);
};