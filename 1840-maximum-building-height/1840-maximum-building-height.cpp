class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& A) {
        map<long, long> m{ {1,0} };
        for (auto &v : A) m[v[0]] = v[1];
        long ans = 0;
        for (auto it = next(begin(m)); it != end(m);) {
            auto [x1, h1] = *prev(it);
            auto [x2, h2] = *it;
            if (h2 >= h1 + x2 - x1) {
                it = m.erase(it);
            } else {
                it = next(it);
            }
        }
        for (auto it = prev(end(m)); it != begin(m);) {
            auto [x1, h1] = *prev(it);
            auto [x2, h2] = *it;
            if (h1 >= h2 + x2 - x1) {
                m.erase(prev(it));
            } else {
                it = prev(it);
            }
        }
        for (auto it = next(begin(m)); it != end(m); ++it) {
            auto [x1, h1] = *prev(it);
            auto [x2, h2] = *it;
            long x = (h2 - h1 + x1 + x2) / 2;
            ans = max(ans, h1 + x - x1);
        }
        auto [x, h] = *rbegin(m);
        ans = max(ans, h + n - x);
        return ans;
    }
};