class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> cnt;
        cnt.reserve(words.size()*2);
        for (auto& w : words) ++cnt[w];
        int res = 0;
        for (auto& p : cnt) {
            const string& w = p.first;
            int c = p.second;
            string rev = w;
            swap(rev[0], rev[1]);
            if (w < rev && cnt.count(rev)) {
                res += 4 * min(c, cnt[rev]);
            }
        }
        for (auto& p : cnt) {
            const string& w = p.first;
            int c = p.second;
            if (w[0] == w[1]) {
                res += 4 * (c / 2);
            }
        }
        for (auto& p : cnt) {
            const string& w = p.first;
            int c = p.second;
            if (w[0] == w[1] && (c & 1)) {
                res += 2;
                break;
            }
        }
        return res;
    }
};