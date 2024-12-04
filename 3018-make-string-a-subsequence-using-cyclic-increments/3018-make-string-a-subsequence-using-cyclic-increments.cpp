class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int target =0;
        int targetLen = str2.length();

        for(char currChar : str1){
            if(target < targetLen && (str2[target] - currChar +26) % 26 <=1) {
                target++;
            }
        }
        return target == targetLen;
    }
};