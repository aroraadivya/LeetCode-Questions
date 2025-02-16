class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size, 0); 
        vector<bool> used(n + 1, false); 
        
        function<bool(int)> backtrack = [&](int idx) {
            if (idx == size) return true;
            if (result[idx] != 0) return backtrack(idx + 1);
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue;
                
                if (num == 1) {
                    result[idx] = 1;
                    used[num] = true;
                    if (backtrack(idx + 1)) return true;
                    result[idx] = 0;
                    used[num] = false;
                } else {  
                    int secondPos = idx + num;
                    if (secondPos < size && result[secondPos] == 0) {
                        result[idx] = result[secondPos] = num;
                        used[num] = true;
                        
                        if (backtrack(idx + 1)) return true;
                    
                        result[idx] = result[secondPos] = 0;
                        used[num] = false;
                    }
                }
            }
            return false;
        };
        
        backtrack(0);
        return result;
    }
};
