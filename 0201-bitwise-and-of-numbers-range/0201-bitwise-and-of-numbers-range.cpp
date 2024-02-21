class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 0; i<32; ++i)
        {
            if(((left>>i) & 1) == ((right>>i) & 1))
            ans |= ((1<<i)&left);
            else ans = 0;
        }
        return ans;
    }
};