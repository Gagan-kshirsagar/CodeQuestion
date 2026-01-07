int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_consecutive = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 1){
                max_consecutive = max(max_consecutive, count);
                count = 0;
                continue;
            }
            ++count;
        }

        return max(max_consecutive, count);
    }