class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 == 1) {
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};