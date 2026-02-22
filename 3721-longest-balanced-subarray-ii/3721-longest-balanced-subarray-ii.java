import java.lang.*;

class Node {
    public int min;
    public int max;
    public int delta;

    public Node(int min, int max, int delta) {
        this.min = min;
        this.max = max;
        this.delta = delta;
    }
}

class SegmentTree {
    private int n;
    private Node[] tree;

    private void merge(int node) {
        Node left = tree[node << 1];
        Node right = tree[(node << 1) | 1];

        tree[node].min = Math.min(left.min, right.min);
        tree[node].max = Math.max(left.max, right.max);
    }

    public SegmentTree(int n) {
        this.n = n;
        this.tree = new Node[4 * n];
        build(1, 0, n - 1);
    }

    private void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = new Node(0, 0, 0);
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = new Node(0, 0, 0);
        merge(node);
    }

    public void changeNode(int node, int value) {
        tree[node].min += value;
        tree[node].max += value;
        tree[node].delta += value;
    }

    public void update(int l, int r, int value) {
        update(1, 0, n - 1, l, r, value);
    }

    private void update(int node, int tl, int tr, int l, int r, int value) {
        if (l > r)
            return;
        if (l <= tl && tr <= r) {
            changeNode(node, value);
            return;
        }
        push(node);
        int mid = (tl + tr) / 2;
        update(2 * node, tl, mid, l, Math.min(mid, r), value);
        update(2 * node + 1, mid + 1, tr, Math.max(l, mid + 1), r, value);
        merge(node);
    }

    public int query() {
        return query(1, 0, n - 1);
    }

    private int query(int node, int start, int end) {
        if (tree[node].min > 0 || tree[node].max < 0)
            return -1;
        if (start == end)
            return start;
        push(node);
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid);
        if (left == -1)
            return query(2 * node + 1, mid + 1, end);
        return left;
    }

    private void push(int node) {
        int delta = tree[node].delta;
        changeNode(node << 1, delta);
        changeNode((node << 1) | 1, delta);
        tree[node].delta = 0;
    }
}

class Solution {
    private int sign(int i) {
        return i % 2 == 0 ? 1 : -1;
    }

    public int longestBalanced(int[] nums) {
        int n = nums.length, ans = 0;
        int[] base = new int[n];
        SegmentTree tree = new SegmentTree(n);
        Map<Integer, Integer> occur = new HashMap<>();
        for (int r = 0; r < n; ++r) {
            int prev = occur.getOrDefault(nums[r], -1) + 1;
            tree.update(prev, r, sign(nums[r]));
            int l = tree.query();
            if (l != -1)
                ans = Math.max(ans, r - l + 1);
            occur.put(nums[r], r);
        }
        return ans;
    }
}