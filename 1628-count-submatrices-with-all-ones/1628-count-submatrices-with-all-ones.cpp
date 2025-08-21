#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> newmat(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            newmat[i][m-1] = mat[i][m-1] == 0 ? 0 : 1;
            for (int j = m-2; j >= 0; j--) {
                newmat[i][j] = mat[i][j] == 0 ? 0 : newmat[i][j+1] + 1;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minwidth = newmat[i][j];
                for (int d = i; d < n; d++) {
                    if (newmat[d][j] == 0) break;
                    minwidth = min(minwidth, newmat[d][j]);
                    count += minwidth;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};
    cout << sol.numSubmat(mat) << endl;
    return 0;
}