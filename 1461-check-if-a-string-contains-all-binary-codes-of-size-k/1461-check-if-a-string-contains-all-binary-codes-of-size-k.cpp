class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        unordered_set<string> seen;
        int need = 1 << k;
        for (int i = 0; i <= (int)s.length() - k; i++) {
            seen.insert(s.substr(i, k));
            if (seen.size() == need) return true;
        }
        return false;
    }
};