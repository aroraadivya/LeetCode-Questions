class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        
        if (n == 1) {
            return derived[0] == 0;
        }
        
        vector<int> original(n);
        original[0] = 0;
        for (int i = 0; i < n-1; i++) {
            original[i+1] = derived[i] ^ original[i];
        }
        
        return (original[n-1] ^ original[0]) == derived[n-1];
    }
};