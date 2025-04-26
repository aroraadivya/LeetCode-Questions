class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderFrequency;
        int count = 0;
        remainderFrequency[0]++;
        long long totalSubarrays = 0;

        for (int i = 0; i < n; i++) {
            count += (nums[i] % m == k);
            int remainder = (count - k) % m;
            if (remainder < 0) remainder += m;
            totalSubarrays += remainderFrequency[remainder];
            remainderFrequency[count % m]++;
        }

        return totalSubarrays;
    }
};