class Solution {
    public boolean hasAlternatingBits(int n) {
        int bit = (n&1)^1;
        while(n>0){
            if(bit == (n&1)) return false;
            else bit = (n&1);
            n >>= 1;
        }
        return true;
    }
}