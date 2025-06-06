class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n + 1, 0);
        vector<vector<int>> components;
        
        function<bool(int, vector<int>&)> bfs = [&](int start, vector<int>& component) {
            queue<int> q;
            q.push(start);
            color[start] = 1;
            component.push_back(start);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                        component.push_back(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
            return true;
        };
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                vector<int> component;
                if (!bfs(i, component)) {
                    return -1;
                }
                components.push_back(component);
            }
        }
        
        int maxGroups = 0;
        
        auto getMaxDepth = [&](int start) {
            queue<int> q;
            unordered_map<int, int> dist;
            q.push(start);
            dist[start] = 1;
            int maxDepth = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (!dist.count(neighbor)) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                        maxDepth = max(maxDepth, dist[neighbor]);
                    }
                }
            }
            return maxDepth;
        };
        
        for (auto& component : components) {
            int localMax = 0;
            for (int node : component) {
                localMax = max(localMax, getMaxDepth(node));
            }
            maxGroups += localMax;
        }
        
        return maxGroups;
    }
};

int Main() {
    Solution sol;
    vector<vector<int>> edges1 = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}};
    cout << sol.magnificentSets(6, edges1) << endl;
    
    vector<vector<int>> edges2 = {{1,2},{2,3},{3,1}};
    cout << sol.magnificentSets(3, edges2) << endl;
    
    return 0;
}