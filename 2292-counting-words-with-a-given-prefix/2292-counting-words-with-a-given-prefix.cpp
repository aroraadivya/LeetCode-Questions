class Solution {
public:
    int prefixCount(vector<string>& words, string prefix) {
        int count = 0;
        for (const string& word : words) {
            if (word.substr(0, prefix.size()) == prefix) {
                count++;
            }
        }
        return count;
    }
};