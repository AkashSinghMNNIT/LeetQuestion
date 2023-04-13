class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, n = pushed.size(), m = popped.size();
        
        for(auto x: pushed)
        {
            pushed[i++] = x;
            while(i>0 && pushed[i-1]==popped[j]) i--, j++;
        }
        
        return i==0;
    }
};