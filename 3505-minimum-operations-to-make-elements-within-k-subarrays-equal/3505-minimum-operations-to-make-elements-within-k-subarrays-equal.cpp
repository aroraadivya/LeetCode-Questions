#define ll long long

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // left stores the smaller half of the current window.
        // right stores the larger half of the current window.
        // The median is the maximum element of left.
        multiset<int> left, right;

        // Sum of elements in the two multisets.
        ll Lsum = 0;
        ll Rsum = 0;

        // Number of elements in the two multisets.
        int Lsize = 0;
        int Rsize = 0;

        // op[i] stores the minimum operations required
        // to make all elements equal in the window
        // nums[i-x+1 ... i].
        vector<ll> op(n, 0);

        // --------------------------------------------------
        // STEP 1: Calculate the cost of every window of size x
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            // If the window already contains x elements,
            // remove the element that is leaving the window.
            if (Lsize + Rsize == x) {

                auto itleft = left.find(nums[i-x]);

                // If the outgoing element is present in left,
                // remove it and update the corresponding sum.
                if (itleft != left.end()) {
                    left.erase(itleft);
                    Lsum -= nums[i-x];
                    Lsize--;
                }
                else {
                    // Otherwise, the outgoing element is in right.
                    auto itright = right.find(nums[i-x]);

                    right.erase(itright);
                    Rsum -= nums[i-x];
                    Rsize--;
                }
            }

            // --------------------------------------------------
            // Insert the current element into the correct half.
            // --------------------------------------------------

            auto LMX = left.end();
            auto RMN = right.begin();

            // If left is empty, or the current element is
            // smaller than or equal to the maximum of left,
            // insert it into left.
            if (left.size() == 0 || nums[i] <= *prev(LMX)) {
                left.insert(nums[i]);
                Lsum += nums[i];
                Lsize++;
            }
            else {
                // Otherwise, insert it into right.
                right.insert(nums[i]);
                Rsum += nums[i];
                Rsize++;
            }

            ll mid;

            // --------------------------------------------------
            // Balance the two multisets.
            // --------------------------------------------------

            // Ensure the sizes of left and right differ by
            // at most one element.
            if (abs(Lsize-Rsize) <= 1) {

                // If right has more elements than left,
                // move the smallest element of right to left.
                if (Lsize < Rsize) {
                    auto it = right.begin();

                    Lsum += *it;
                    Rsum -= *it;

                    Lsize++;
                    Rsize--;

                    left.insert(*it);
                    right.erase(it);
                }

                // The maximum element of left is the median.
                mid = *prev(left.end());
            }
            else {

                // If right has more elements than left,
                // move its smallest element to left.
                if (Lsize < Rsize) {
                    auto it = right.begin();

                    Lsum += *it;
                    Rsum -= *it;

                    Lsize++;
                    Rsize--;

                    left.insert(*it);
                    right.erase(it);
                }
                else {
                    // If left has more elements than right,
                    // move its maximum element to right.
                    auto it = prev(left.end());

                    Lsum -= *it;
                    Rsum += *it;

                    Lsize--;
                    Rsize++;

                    right.insert(*it);
                    left.erase(it);
                }

                // After balancing, the maximum of left
                // is the median.
                mid = *prev(left.end());
            }

            // --------------------------------------------------
            // Calculate the cost of the current window.
            // --------------------------------------------------

            if (i >= x-1) {

                // For a window with median mid:
                //
                // Cost of changing all elements to mid:
                //
                // left side:
                // Lsum - mid - (Lsize-1)*mid
                //
                // right side:
                // Rsum - Rsize*mid
                //
                // The expression below combines both sides
                // and accounts for the median in left.
                op[i] = abs(
                    Rsum - (Lsum-mid)
                    - abs((Lsize-1)-Rsize)*mid
                );
            }
        }

        // --------------------------------------------------
        // STEP 2: Dynamic programming
        // --------------------------------------------------

        // dp[i][kk] represents the minimum operations required
        // to select kk non-overlapping subarrays of length x
        // from the first i elements.
        //
        // LLONG_MAX represents an impossible state.
        vector<vector<ll>> dp(
            n+1,
            vector<ll>(k+1, LLONG_MAX)
        );

        // Selecting zero subarrays always costs zero.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // --------------------------------------------------
        // STEP 3: Fill the DP table
        // --------------------------------------------------

        for (int i = 1; i <= n; i++) {

            // We cannot select more than i/x subarrays
            // because every subarray has length x.
            for (int kk = 1; kk <= i/x && kk <= k; kk++) {

                // Option 1:
                // Do not select a subarray ending at index i-1.
                // Use the answer from the first i-1 elements.
                dp[i][kk] = dp[i-1][kk];

                // Option 2:
                // Select the subarray nums[i-x ... i-1].
                //
                // Its cost is op[i-1].
                // The previous kk-1 subarrays must lie entirely
                // within the first i-x elements.
                //
                // This guarantees that the selected subarrays
                // do not overlap.
                if (dp[i-x][kk-1] != LLONG_MAX) {
                    dp[i][kk] = min(
                        dp[i][kk],
                        op[i-1] + dp[i-x][kk-1]
                    );
                }
            }
        }

        // Minimum cost to select exactly k non-overlapping
        // subarrays of length x from the entire array.
        return dp[n][k];
    }
};