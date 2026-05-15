class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        int n = nums.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;

            std::cout << start <<" " <<mid <<" "<<end<<"\n";

            if (nums[n - 1] < nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return nums[start];
    }
};