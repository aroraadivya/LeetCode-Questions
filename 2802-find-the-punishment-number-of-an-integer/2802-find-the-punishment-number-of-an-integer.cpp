class Solution {
public:
    bool canPartition(string numStr, int target, int index, int currentSum) {
        if (index == numStr.size()) {
            return currentSum == target;
        }
        
        int sum = 0;
        for (int i = index; i < numStr.size(); i++) {
            sum = sum * 10 + (numStr[i] - '0');
            if (sum + currentSum > target) break;
            if (canPartition(numStr, target, i + 1, currentSum + sum)) {
                return true;
            }
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int totalSum = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string squareStr = to_string(square);
            if (canPartition(squareStr, i, 0, 0)) {
                totalSum += square;
            }
        }
        return totalSum;
    }
};