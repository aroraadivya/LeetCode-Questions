class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper){ 
        int n = nums.size();
        long long ans = 0;
        
        sort(nums.begin(), nums.end());

        for(long long i=0; i<n; i++){
        long long itr1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
                
        long long itr2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;

        if (itr2 >= itr1){
            ans += itr2 - itr1 + 1;
            }
        }
        return ans;
    }
};