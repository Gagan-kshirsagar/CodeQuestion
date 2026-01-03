vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++){
        int res = target - nums[i];
        if(map.count(res)){
            return {map[res], i};
        }
        map[nums[i]] - i;
    }
    return {};
}