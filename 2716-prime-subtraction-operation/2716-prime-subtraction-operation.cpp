class Solution {
public:
    bool isPrime(int n){
        if (n <= 1){
            return false;
        }
     
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        
        int n = nums.size(), prev = -1; 
        
        for(int i=0; i<n; i++) {
            if(nums[i] <= prev) return false;
            bool found = false;
            
            for(int curr = nums[i]-1; curr>1; curr--){
                if(isPrime(curr)){
                    if(prev >= nums[i]-curr){
                        continue;
                    }
                    
                    prev = nums[i] - curr;
                    found = true;
                    break;
                    }
                }
            
            if(!found){
                if(nums[i] > prev) prev = nums[i];
                else return false;
                }
            }
            return true;
    }
};