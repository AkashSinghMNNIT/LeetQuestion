class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles >= numExchange)
        {
            numBottles -= numExchange;
            ans += numExchange++, numBottles++;
        }
        return ans + numBottles;
    }
};