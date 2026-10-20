class Solution {
public:
    bool cyclicSort(int start , int end , vector<int>&nums)
    {
        int cnt=0;
        for(int i=start+1 ; i<end ; i++) if(nums[i]<nums[i-1]) cnt++;
        if(nums[start]<nums[end-1]) cnt++;
        return cnt<=1;
    }

    bool solve(int gap , vector<int>&nums , int n)
    {
        int prevMax=INT_MIN;
        for(int i=0 ; i<n ; i+=gap)
        {
            int currMin=INT_MAX;
            int currMax=INT_MIN;
            for(int j=i ; j<i+gap ; j++) 
            {
                currMin=min(currMin,nums[j]);
                currMax=max(currMax,nums[j]);
            }
            if(prevMax>currMin || !cyclicSort(i,i+gap,nums)) return false;
            prevMax=currMax;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) 
    {
        int n=nums.size() , ans=0;
        for(int gap=1 ; gap<=n ; gap++) if(n%gap==0 && solve(gap,nums,n)) ans+=gap;
        return ans;
    }
};