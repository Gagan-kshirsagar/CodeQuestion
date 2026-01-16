public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // Calculate all possible horizontal side lengths
        unordered_set<int> hGaps;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                hGaps.insert(abs(hFences[i] - hFences[j]));
            }
        }

        // Find the maximum common side length in vertical gaps
        long long maxSide = -1;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                int gap = abs(vFences[i] - vFences[j]);
                if (hGaps.count(gap)) {
                    maxSide = max(maxSide, (long long)gap);
                }
            }
        }

        if (maxSide == -1) return -1;

        // Return area modulo 10^9 + 7
        return (maxSide * maxSide) % 1000000007;
    }
};
