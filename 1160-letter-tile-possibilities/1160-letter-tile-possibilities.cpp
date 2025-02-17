class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freqMap;
        for (char c : tiles) {
            freqMap[c]++;
        }
        return dfs(freqMap);
    }

private:
    int dfs(unordered_map<char, int>& freqMap) {
        int count = 0;
        for (auto& entry : freqMap) {
            if (entry.second > 0) {
                count++;
                entry.second--;
                count += dfs(freqMap);
                entry.second++;
            }
        }
        return count;
    }
};

int Main() {
    Solution sol;
    cout<<sol.numTilePossibilities("AAB")<<endl;
    cout<<sol.numTilePossibilities("AAABBC")<<endl;
    cout<<sol.numTilePossibilities("V")<<endl;
    return 0;
}
