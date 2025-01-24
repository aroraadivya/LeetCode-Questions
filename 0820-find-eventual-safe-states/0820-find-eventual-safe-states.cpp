class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> safeNodes;
        
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, color)) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color) {
        if (color[node] > 0) {
            return color[node] == 2;
        }
        
        color[node] = 1;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 1 || !dfs(graph, neighbor, color)) {
                return false;
            }
        }
        
        color[node] = 2;
        return true;
    }
};