int sumFourDivisors(vector<int>& nums) {
    int res = 0;
    if(nums.empty()) return 0;

    for(int i = 0; i < nums.size(); i++){
        vector<int> divisors;
        for(int j = 2; j <= nums[i]/2; j++){
            if(nums[i] % j == 0){
                divisors.push_back(j);
                if(divisors.size() == 2) break;
            }
        }
        ++res;
        res += nums[i];
        for(int k = 0; k < divisors.size(); k++){
            res += divisors[k];
        }
    }
    return res;
}




int sumFourDivisors(vector<int>& nums) {
    int res = 0;
    if(nums.empty()) return 0;

    for(auto num : nums) {
        int cnt = 0, sum = 0;
        for(int i = 1; i * i <= num; ++i) {
            if(num % i == 0) {
                cnt++;
                sum += i;
                if(i * i != num) {
                    cnt++;
                    sum += num / i;
                }
            }
            if(cnt > 4) break;
        }
        if(cnt == 4) res += sum;
    }
    return res;
}
