class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int num1 =0, num2=0;

        if(size1 % 2 != 0){
            for(int num : nums2){
                num2 ^= num;
            }
        }
        if(size2 % 2 != 0){
            for(int num :nums1){
                num1 ^= num;
            }
        }
        return num1 ^ num2;
    }
};