#define f(x) __builtin_popcount(x)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        stable_sort(begin(nums), end(nums), [&](int a, int b) { return f(a) == f(b) && a < b; });
        return is_sorted(begin(nums), end(nums));
    }
};