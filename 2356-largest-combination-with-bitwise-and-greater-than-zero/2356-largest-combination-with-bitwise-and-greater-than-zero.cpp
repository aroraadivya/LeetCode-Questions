class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int n = candidates.size();

        for(int i =0; i<32; i++){
            int count = 0;

            for(auto candidate:candidates){
                if(candidate & (1<<i)){
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};