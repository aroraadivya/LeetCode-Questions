class Solution {
public:
    static inline void build_adj(const vector<vector<int>>& edges,  vector<vector<int>>& adj){
        for (const auto& e: edges){
            const int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    static int dfs(int i, int parent,  bool isEven, bitset<100001>& even, const vector<vector<int>>& adj){
        int cnt=isEven;
        even[i]=isEven;
        for(int j:adj[i]){
            if (j==parent) continue;
            cnt+=dfs(j, i, !isEven, even, adj);
        }
        return cnt;
    }
    static int dfs0(int i, int parent,  bool isEven, const vector<vector<int>>& adj){
        int cnt=isEven;
        for(int j:adj[i]){
            if (j==parent) continue;
            cnt+=dfs0(j, i, !isEven, adj);
        }
        return cnt;
    }
    static vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const int n=edges1.size()+1, m=edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);
        bitset<100001> even1=0;
        build_adj(edges1, adj1);
        build_adj(edges2, adj2);
        int y=dfs0(0, -1, 1, adj2);// no need for even for tree2
        int x=dfs(0, -1, 1, even1, adj1);
        
        vector<int> ans(n);
        const int cnt2=max(y, m-y);
        for(int i=0; i<n; i++){
            ans[i]=(even1[i])?x+cnt2:(n-x)+cnt2;
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();