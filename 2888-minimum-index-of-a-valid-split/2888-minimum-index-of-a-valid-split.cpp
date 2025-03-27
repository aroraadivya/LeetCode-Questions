class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n = nums.size();
        int cnt = 0, xM = 0;
        for (int x : nums) {
            if (cnt == 0) xM = x;
            cnt += (x == xM) ? 1 : -1;
        }

        int maxCount = count(nums.begin(), nums.end(), xM);
        int cntxM = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == xM) cntxM++;
            if (cntxM * 2 > (i + 1) && (maxCount - cntxM) * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
