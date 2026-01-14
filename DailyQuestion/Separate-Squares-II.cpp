class Solution {
    struct Event {
        int y, x1, x2, type;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    struct Node {
        int count = 0;
        long long length = 0;
    };

    vector<Node> tree;
    void update(int v, int tl, int tr, int l, int r, int add, const vector<int>& x_coords) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].count += add;
        } else {
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add, x_coords);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add, x_coords);
        }
        
        if (tree[v].count > 0) {
            tree[v].length = x_coords[tr + 1] - x_coords[tl];
        } else if (tl != tr) {
            tree[v].length = tree[2 * v].length + tree[2 * v + 1].length;
        } else {
            tree[v].length = 0;
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<int> x_coords;
        for (auto& s : squares) {
            int x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, 1});      // Bottom edge
            events.push_back({y + l, x, x + l, -1}); // Top edge
            x_coords.push_back(x);
            x_coords.push_back(x + l);
        }

        sort(events.begin(), events.end());
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

        auto get_idx = [&](int x) {
            return lower_bound(x_coords.begin(), x_coords.end(), x) - x_coords.begin();
        };

        int m = x_coords.size();
        tree.assign(4 * m, Node());

        // First pass: Calculate total union area
        double totalArea = 0;
        for (int i = 0; i < events.size() - 1; ++i) {
            update(1, 0, m - 2, get_idx(events[i].x1), get_idx(events[i].x2) - 1, events[i].type, x_coords);
            totalArea += (double)tree[1].length * (events[i + 1].y - events[i].y);
        }

        // Second pass: Find the y-coordinate that splits area in half
        tree.assign(4 * m, Node());
        double currentArea = 0;
        double targetArea = totalArea / 2.0;

        for (int i = 0; i < events.size() - 1; ++i) {
            update(1, 0, m - 2, get_idx(events[i].x1), get_idx(events[i].x2) - 1, events[i].type, x_coords);
            double nextArea = (double)tree[1].length * (events[i + 1].y - events[i].y);
            
            if (currentArea + nextArea >= targetArea) {
                double needed = targetArea - currentArea;
                return events[i].y + (needed / (double)tree[1].length);
            }
            currentArea += nextArea;
        }

        return events.back().y;
    }
};
