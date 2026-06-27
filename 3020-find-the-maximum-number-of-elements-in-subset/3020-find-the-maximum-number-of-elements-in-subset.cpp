class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        unordered_map<int,int>mp;
        unordered_set<int>st;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
        }

        vector<int>v;
        for(auto i:st){
            if(i != 1){
                v.push_back(i);
            }
        }

        sort(v.begin(),v.end());

        int maxi = 1;

        int onecnt = mp[1];
        if(onecnt > 0){
            if(onecnt % 2 == 0){
                onecnt--;
            }
            maxi = max(maxi,onecnt);
        }

        for(int i=0;i<v.size();i++){
            long long ele = v[i];
            int cnt = mp[ele];
            int ans = 0;
            if(cnt == 1){
                continue;
            }
            else{
                ans += 2;
            }
            while(true){
                ele = (long long) (ele * ele);
                cnt = mp[ele];
                if(ele > 3037000499LL){
                    if(ans == 2){
                        ans = 0;
                    }
                    else{
                        ans--;
                    }
                    break;
                }
                else if(cnt == 1){
                    ans += 1;
                    break;
                }
                else if(cnt >= 2){
                    ans += 2;
                }
                else if(cnt == 0){
                    if(ans == 2){
                        ans = 0;
                    }
                }
            }
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};