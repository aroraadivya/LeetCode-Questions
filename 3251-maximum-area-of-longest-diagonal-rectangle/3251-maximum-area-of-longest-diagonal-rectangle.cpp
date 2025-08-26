class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0, maxDia = 0;
        for (auto &dim : dimensions) {
            int l = dim[0], b = dim[1];
            int currDia = l * l + b * b;
            int currArea = l * b;
            if (currDia > maxDia || (currDia == maxDia && currArea > maxArea)) {
                maxDia = currDia;
                maxArea = currArea;
            }
        }
        return maxArea;
    }
};