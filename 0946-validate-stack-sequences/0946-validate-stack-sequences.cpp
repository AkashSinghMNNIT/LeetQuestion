class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, n = pushed.size(), m = popped.size();
        stack<int> st;
        
        for(auto x: pushed)
        {
            st.push(x);
            while(!st.empty() && i<m && popped[i]==st.top())  st.pop(), i++;
        }
        
        return i==m;
    }
};