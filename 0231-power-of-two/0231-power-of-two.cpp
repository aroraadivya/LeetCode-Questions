class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && popcount(unsigned(n))==1;
    }
};