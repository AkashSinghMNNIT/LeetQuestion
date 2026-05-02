class Solution {
    private boolean isGood(int i){
        boolean flag = false;
        while(i>0){
            int x = i%10;
            if(x==2 || x==5 || x==6 || x==9) flag = true;
            else if(x==3 || x==4 || x==7) return false;
            i /= 10;
        }
            return flag;
    }
    public int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i<=n; ++i){
            if(isGood(i)) ++ans;
        }
        return ans;
    }
}