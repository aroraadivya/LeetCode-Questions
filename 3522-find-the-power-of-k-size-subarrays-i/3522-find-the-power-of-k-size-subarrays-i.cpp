class Solution {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> results;

        for (int i = 0; i <= n - k; ++i) {
            std::vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            bool is_consecutive = true;
            
            for (int j = 1; j < k; ++j) {
                if (subarray[j] != subarray[j - 1] + 1) {
                    is_consecutive = false;
                    break;
                }
            }
            
            if (is_consecutive) {
                int max_element = *std::max_element(subarray.begin(), subarray.end());
                results.push_back(max_element);
            } else {
                results.push_back(-1);
            }
        }

        return results;
    }
};
