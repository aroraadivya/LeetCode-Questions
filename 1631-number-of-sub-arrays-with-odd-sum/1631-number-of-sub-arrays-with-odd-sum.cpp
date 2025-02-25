class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1;
        int prefixSum = 0, result = 0;

        for(int num:arr){
            prefixSum+=num;

            if(prefixSum % 2==0){
                result=(result+oddCount)%MOD;
                evenCount++;
            }else{
                result=(result+evenCount)%MOD;
                oddCount++;
            }
        }
        return result;
    }
};