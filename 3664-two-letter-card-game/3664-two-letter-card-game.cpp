class Solution {
public:
    int score(vector<string>& cards, char x) {
        int n = cards.size(), countXX = 0, tL = 0, tR = 0, maxL = 0, maxR = 0;
        int cL[26] = {0}, cR[26] = {0}, ans = 0;
        for (auto it : cards) {
            if (it[0] == x) {
                if (it[1] == x)
                    ++countXX;
                else
                    ++tR, ++cR[it[1] - 'a'], maxR = max(maxR, cR[it[1] - 'a']);
            } else if(it[1]==x)
                ++tL, ++cL[it[0] - 'a'], maxL = max(maxL, cL[it[0] - 'a']);
        }
        for (int i = 0; i <= countXX; ++i) {
            int newtL = tL + i, newmaxL = max(maxL, i),
                leftP = max(newtL / 2, newtL - newmaxL);
            int newtR = tR + countXX - i, newmaxR = max(maxR, countXX - i),
                rightP = max(newtR / 2, newtR - newmaxR);
            ans = max(ans, leftP + rightP);
        }

        return ans;
    }
};