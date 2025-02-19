class Solution {
public:
    void generateHappyStrings(int n, string &current, vector<string> &happyStrings) {
        if (current.length() == n) {
            happyStrings.push_back(current);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                generateHappyStrings(n, current, happyStrings);
                current.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current;
        generateHappyStrings(n, current, happyStrings);
        return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";
    }
};
