class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int count = 0, i = 0;
            while (i < nums.size()) {
                if (nums[i] <= mid) {
                    count++;
                    i++;
                }
                i++;
            }

            if (count >= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
