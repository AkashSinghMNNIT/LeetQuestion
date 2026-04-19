class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int mid = arr[(n-1)/2];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)->{
            if(a[0]==b[0]) return b[1]-a[1];
            return b[0]-a[0];
        });
        for(int i: arr){
            pq.offer(new int[]{Math.abs(i-mid), i});
        }
        int[] ans = new int[k];
        for(int i = 0; i<k; ++i) ans[i] = pq.poll()[1];
        return ans;
    }
}