class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = findMaxGap(hBars);
        int maxV = findMaxGap(vBars);
        int side = min(maxH, maxV);
        return side * side;
    }

private:
    int findMaxGap(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int maxStreak = 1;
        int currentStreak = 1;
        
        for (int i = 1; i < bars.size(); ++i) {
            if (bars[i] == bars[i - 1] + 1) {
                currentStreak++;
            } else {
                currentStreak = 1;
            }
            maxStreak = max(maxStreak, currentStreak);
        }
        return maxStreak + 1;
    }
};
