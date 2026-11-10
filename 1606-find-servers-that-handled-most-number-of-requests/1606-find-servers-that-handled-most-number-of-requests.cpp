constexpr int N=1e5;
using u64=uint64_t;
u64 busy[N];// packed pair ( time, server id)
int freq[N];
bitset<N> Free;
inline u64 pack(int t, int id){ return ((u64)t<<17)+id; }
class Solution {
public:
    static vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        const int n=arrival.size();
        if (n<=k){// special case
            vector<int> ans(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }
        // reset fot this testcase
        memset(freq, 0, k*sizeof(int));
        Free.set();
    
        for(int i=0; i<k; i++){
            freq[i]++;
            busy[i]=pack(arrival[i]+load[i], i);
            Free[i]=0;
        }
        priority_queue<u64, vector<u64>, greater<u64>> pq(busy, busy+k);
        constexpr int mask=(1<<17)-1;
        int maxF=1;
        for(int i=k; i<n; i++){
            int t0=arrival[i], t=t0+load[i];
            u64 data;
            while( !pq.empty() && ((data=pq.top())>>17)<=t0){
                int id=data & mask;
                Free[id]=1;
                pq.pop();
            }
            if ( pq.size()>=k) continue; // all servers are busy
            int i0=(i>=k)?i%k:i;
            if (Free[i0]){
                maxF=max(++freq[i0], maxF);
                Free[i0]=0;
                pq.push(pack(t, i0));
            }
            else{
                int nxt=Free._Find_next(i0);
                if (nxt>=k) nxt=Free._Find_first();
                maxF=max(++freq[nxt], maxF);
                Free[nxt]=0;
                pq.push(pack(t, nxt));
            }
        }
        vector<int> ans;
        ans.reserve(k);
        for(int i=0; i<k; i++)
            if (freq[i]==maxF) ans.push_back(i);

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();