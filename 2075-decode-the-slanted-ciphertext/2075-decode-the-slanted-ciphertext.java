class Solution {
    public String decodeCiphertext(String eT, int rows) {
        int size = eT.length();
        int col = size/rows;
        StringBuilder ans = new StringBuilder(" ".repeat(size));
        for(int i = 0; i<size; ++i){
            int x = i/col;
            int y = i%col;
            if(y>=x)
            {
                ans.setCharAt(rows*(y-x) + x, eT.charAt(i));
            }
        }
        return ans.toString().replaceAll("\\s+$", "");
        
    }
}