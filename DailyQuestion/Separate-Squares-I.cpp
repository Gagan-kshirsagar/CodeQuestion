public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double minY = 1e9, maxY = -1e9;

        for (const auto& sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }

        double halfArea = totalArea / 2.0;
        double left = minY, right = maxY;

        for (int iter = 0; iter < 100; ++iter) { 
            double mid = left + (right - left) / 2.0;
            double areaBelowMid = 0.0;

            for (const auto& sq : squares) {
                double y = sq[1];
                double l = sq[2];
                // Calculate height of the square portion below 'mid'
                double height = max(0.0, min(mid, y + l) - max((double)y,       (double)minY)); 
                areaBelowMid += height * l;
            }

            if (areaBelowMid < halfArea) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        // Return left or right, they are very close at this point
        return left;
    }
};