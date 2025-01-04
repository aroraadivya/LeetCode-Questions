class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> leftCount(26, 0), rightCount(26, 0);
        unordered_set<string> uniquePalindromes;

        for (char c : s) {
            rightCount[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            char middle = s[i];
            rightCount[middle - 'a']--;

            for (int c = 0; c < 26; c++) {
                if (leftCount[c] > 0 && rightCount[c] > 0) {
                    string palindrome = string(1, 'a' + c) + middle + string(1, 'a' + c);
                    uniquePalindromes.insert(palindrome);
                }
            }

            leftCount[middle - 'a']++;
        }

        return uniquePalindromes.size();
    }
};
