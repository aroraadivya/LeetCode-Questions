class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start = 0;
        long long sum = 0;
        long long count = 0;
        
        // Iterate through the array using the 'end' pointer
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            
            // Shrink the window if the score exceeds or equals 'k'
            while (sum * (end - start + 1) >= k) {
                sum -= nums[start];
                start++;
            }
            
            // Add the number of valid subarrays ending at 'end'
            count += (end - start + 1);
        }
        
        return count;
    }
};