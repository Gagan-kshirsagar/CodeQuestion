long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long totalSum = 0;
    int negativeCount = 0;
    int minAbsValue = INT_MAX;

    for(const auto&row : matrix){
        for(int val : row){
            totalSum += abs(val);
            if(val < 0) negativeCount++;
            minAbsValue = min(minAbsValue, abs(val));
        }
    }

    if(negativeCount != 0){
        totalSum -= 2LL * minAbsValue;
    }

    return totalSum;
}
