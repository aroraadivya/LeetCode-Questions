class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minPositiveSum=INT_MAX;
        bool found = false;

        for(int size=l;size<=r;++size){
            int currentSum=0;

            for(int i=0;i<size;++i){
                currentSum+=nums[i];
            }
            if(currentSum>0){
                minPositiveSum=min(minPositiveSum, currentSum);
                found=true;
            }

            for(int i=size; i<n; ++i){
                currentSum+=nums[i] - nums[i-size];

                if(currentSum>0){
                    minPositiveSum=min(minPositiveSum, currentSum);
                    found = true;
                }
            }
        }
        return found ? minPositiveSum : -1;
    }
};