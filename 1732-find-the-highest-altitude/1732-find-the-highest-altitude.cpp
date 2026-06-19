class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>presum;
        presum.push_back(0);
        for(int i=0;i<gain.size();i++)
        {
            presum.push_back(presum[i]+gain[i]);
        }
        sort(presum.begin(),presum.end());
        return presum[presum.size()-1];
    }
};