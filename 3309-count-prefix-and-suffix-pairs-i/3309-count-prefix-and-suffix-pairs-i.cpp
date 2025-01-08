class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 > len2) return false;

        for (int i = 0; i < len1; ++i) {
            if (str1[i] != str2[i]) return false;
        }

        for (int i = 0; i < len1; ++i) {
            if (str1[i] != str2[len2 - len1 + i]) return false;
        }

        return true;
    }
};
