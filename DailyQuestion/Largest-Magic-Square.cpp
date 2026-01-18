public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // rowSum[i][j] = sum of grid[i][0...j-1]
        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        // colSum[j][i] = sum of grid[0...i-1][j]
        vector<vector<int>> colSum(n, vector<int>(m + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }

        // Try side length k from largest possible down to 2
        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (isMagic(grid, rowSum, colSum, i, j, k)) {
                        return k;
                    }
                }
            }
        }

        return 1; // Minimum possible magic square is 1x1
    }

private:
    bool isMagic(vector<vector<int>>& grid, vector<vector<int>>& rowSum, 
                 vector<vector<int>>& colSum, int r, int c, int k) {
        
        // Use the first row as the reference target sum
        int target = rowSum[r][c + k] - rowSum[r][c];

        // 1. Check all Rows
        for (int i = r + 1; i < r + k; ++i) {
            if (rowSum[i][c + k] - rowSum[i][c] != target) return false;
        }

        // 2. Check all Columns
        for (int j = c; j < c + k; ++j) {
            if (colSum[j][r + k] - colSum[j][r] != target) return false;
        }

        // 3. Check Main Diagonal
        int diagSum = 0;
        for (int i = 0; i < k; ++i) {
            diagSum += grid[r + i][c + i];
        }
        if (diagSum != target) return false;

        // 4. Check Anti-Diagonal
        int antiDiagSum = 0;
        for (int i = 0; i < k; ++i) {
            antiDiagSum += grid[r + i][c + k - 1 - i];
        }
        if (antiDiagSum != target) return false;

        return true;
    }

