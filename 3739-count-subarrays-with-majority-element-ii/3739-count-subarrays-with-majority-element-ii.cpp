class Solution {
    private:
    long long merge(vector<int> &nums , int l , int mid , int r){
        long long count = 0;
        int j = r;
        // count valid pairs(i , j) on the go
        for(int i = mid; i >= l; i--){
            while(j >= mid + 1  && nums[j] > nums[i]){
                j--;
            }
            count += (r - j);
        }

        int i = l;
        j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid)temp.push_back(nums[i++]);
        while(j <= r)temp.push_back(nums[j++]);
        int index = 0;

        for(int i = l; i <= r; i++){
            nums[i] = temp[index++];
        }
        return count;
    }
    long long mergesort(vector<int> &nums , int l , int r){
        if(l >= r) return 0;
        
        long long count = 0;
        int mid = l + (r - l)  / 2;

        count += mergesort(nums , l , mid);
        count += mergesort(nums , mid + 1 , r);
        count += merge(nums , l , mid , r);
        return count;
    }
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;

        vector<int> arr;
        for(auto x : nums){
            if(x ==  target){
                arr.push_back(1);
            }else{
                arr.push_back(-1);
            }
        }

        vector<int> pref(n + 1 , 0);
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i - 1] + arr[i - 1];
        }

        ans += mergesort(pref , 0 , n);
        return ans;
    }
};