class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=0, count=0;
        for (int num:nums){
            if(num==1){
                maxCount=max(maxCount, ++count);
            }else{
                count=0;
            }
        }
        return maxCount;
    }
};