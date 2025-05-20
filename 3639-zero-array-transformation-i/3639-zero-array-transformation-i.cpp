class Solution {
public:
    static bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n=nums.size(), m=queries.size();
        vector<int> freq(n+1, 0);
        for (const auto& q: queries){
            freq[q[0]]++; 
            freq[q[1]+1]--;             
        }
        int op=0;
        for(int i=0; i<n; i++) {    
            op+=freq[i];
            if (nums[i]>op) return 0;
        }
        return 1;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();