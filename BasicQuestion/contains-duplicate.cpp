bool containsDuplicate(vector<int>& nums){
    if(nums.empty()){
        return false;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i + 1 < nums.size(); i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }

    return false;
}