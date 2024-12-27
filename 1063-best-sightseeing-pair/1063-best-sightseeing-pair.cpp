class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int score = 0;
        int val = values[0];
        for (int i = 1; i < values.size(); i++){
            val--;
            int j = values[i];
            score = max(score, val + j);
            val = max(val, j);
        }
        return score;
    }
};