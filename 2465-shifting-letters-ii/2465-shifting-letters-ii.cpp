class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> shiftSum(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) {
                shiftSum[start] += 1;
                shiftSum[end + 1] -= 1;
            } else {
                shiftSum[start] -= 1;
                shiftSum[end + 1] += 1;
            }
        }
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += shiftSum[i];
            int normalizedShift = (cumulativeShift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + normalizedShift) % 26;
        }

        return s;
    }
};
