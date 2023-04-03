class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int n = people.size(), i = 0, j = n-1, ans = 0;
        
        while(i<=j)
        {
            if(people[i] + people[j] <= limit) --j, ++i;
            else --j;
            ++ans;
        }
        return ans;
    }
};