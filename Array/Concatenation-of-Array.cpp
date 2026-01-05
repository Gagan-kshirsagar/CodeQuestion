vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(2*n);
    for(int i = 0; i < n; i++){
        result[i] = nums[i];
        result[i+n] = nums[i];
    }
    return result;
}


vector<int> getConcatenation(vector<int>& nums) {
    vector<int> result;
    result.reserve(nums.size() * 2); // Reserve space for efficiency
    result.insert(result.end(), nums.begin(), nums.end());
    result.insert(result.end(), nums.begin(), nums.end());
    return result;
}