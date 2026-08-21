using ll=long long;
constexpr int N=1<<15;
ll dp[N];
int GCD[26][26];
class Solution {
public:
    static void computeGCD(){
        if (GCD[1][1]==1) return;// compute once
        for(int i=0; i<26; i++){
            GCD[i][0]=GCD[0][i]=GCD[i][i]=i;
            for(int j=1; j<i; j++){
                GCD[i][j]=GCD[j][i]=GCD[i-j][j];
            }
        }
    }
    static ll f(long long x, unsigned bitMask){
        ll cnt=0;
        for(unsigned i=1; i<=bitMask; i++)
            cnt+=(popcount(i)&1)?(x/dp[i]):(-x/dp[i]);
        return cnt;
    }

    static long long findKthSmallest(vector<int>& coins, int k) {
        computeGCD();
        sort(coins.begin(), coins.end(), greater<>());
        if (coins.back()==1) return k;
        unsigned valid_coin=0;
        for (int c: coins){
            valid_coin|=(1<<c);
            for(int r=2*c; r<26; r+=c) valid_coin&=~(1<<r);
        }
        coins.clear();
        for(; valid_coin; valid_coin&=(valid_coin-1)){ 
            int i=countr_zero(valid_coin);
            coins.push_back(i);
        }

        int sz=coins.size();
        if (sz==1) return (ll)coins[0]*k;

        unsigned bitMask=(1<<sz)-1;
        memset(dp, -1, (1<<sz)*sizeof(ll));

        // Loop through all possible subsets of coins
        for (unsigned bMask=1; bMask<=bitMask; bMask++) {
            ll lcm=1;
            for (unsigned mask=bMask; mask; mask&=(mask-1)) {
                const int i=countr_zero(mask), C=coins[i];
                lcm=lcm/GCD[lcm%C][C]*C ; // compute LCM
            }
            dp[bMask]=lcm;
        }
       
        ll l=k+1, r=(ll)coins[0]*k, mid, ans=r;

        while (l<=r) {
            mid=l+(r-l)/2;
            if (f(mid, bitMask)>=k){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();