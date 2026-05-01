class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long total=0, f=0;

        for(int i=0; i<n; i++){
            total+=nums[i];
            f+=(long long)i*nums[i];
        }

        long long maxf=f;

        for(int k=1; k<n; k++){
            f=f+total - (long long)n * nums[n-k];
            maxf=max(maxf,f);
        }
        return (int)maxf;
    }
};