class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, ans = 0;

        while (i < nums.size()) {
            while (nums[i] - nums[j] > 1) j++;

            if (nums[i] - nums[j] == 1)
                ans = max(ans, i - j + 1);

            i++;
        }

        return ans;
    }
};