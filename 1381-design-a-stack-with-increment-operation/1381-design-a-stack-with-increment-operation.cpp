class CustomStack {
private:
    vector<int> stack, toadd;
    int curr, sz;
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        toadd.resize(maxSize);
        curr = -1, sz = maxSize;
    }

    void push(int x) {
        if(curr<sz-1) stack[++curr] = x;
    }

    int pop() {
        if(curr == -1) return -1;
        int ans = stack[curr] + toadd[curr];
        if(curr>0)toadd[curr-1] += toadd[curr];
        toadd[curr--] = 0;
        return ans;
    }

    void increment(int k, int val) {
        if(curr>=0) toadd[min(curr, k-1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */