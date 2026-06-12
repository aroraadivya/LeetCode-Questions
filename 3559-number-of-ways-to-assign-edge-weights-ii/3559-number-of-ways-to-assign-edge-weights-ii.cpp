class Solution {
public:
    static const int MOD = 1e9 + 7;
    int LOG;

    long long modPow(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& depth,vector<vector<int>>& up) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int neighbour : adj[node]) {
            if (neighbour == parent) continue;

            depth[neighbour] = depth[node] + 1;
            dfs(neighbour, node, adj, depth, up);
        }
    }

    int lca(int u,int v,vector<int>& depth,vector<vector<int>>& up) {
        if (depth[u] < depth[v]) { //always want u to be deeper node
            swap(u, v);
        }

        int diff = depth[u] - depth[v];
        //bringing both nodes to same depth
        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }
        //common ancestor 
        if (u == v) return u;
        // lift both until we do not get a common ancestor
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n + 1, 0);
        vector<vector<int>> up(n + 1, vector<int>(LOG, 0));

        dfs(1, 0, adj, depth, up);

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v, depth, up);
            long long dist =depth[u] + depth[v] - 2LL * depth[L];

            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(modPow(2, dist - 1));
            }
        }

        return ans;
    }
};