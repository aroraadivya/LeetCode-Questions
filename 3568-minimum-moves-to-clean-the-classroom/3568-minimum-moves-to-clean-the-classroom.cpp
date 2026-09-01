class Solution {
    inline static int8_t best[400][1024];
    inline static uint16_t grid[400]; // (is_reset, adj count, litter mask)
    inline static uint16_t adj[400][4];

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int start = 0, litters = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                uint16_t u = r * n + c;
                char ch = classroom[r][c];
                uint16_t val = ch == 'R';
                if (ch == 'S')
                    start = u;
                else if (ch == 'L')
                    val |= 1 << (4 + litters++);
                if (ch != 'X') {
                    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    uint16_t size = 0;
                    for (auto& d : dirs) {
                        uint16_t nr = r + d[0], nc = c + d[1];
                        if (nr < m && nc < n && classroom[nr][nc] != 'X') {
                            adj[u][size++] = nr * n + nc;
                        }
                    }
                    val |= size << 1;
                }
                grid[u] = val;
            }
        }

        int target = (1 << litters) - 1;
        for (int i = 0; i < m * n; ++i) {
            fill(best[i], best[i] + target + 1, -1);
        }

        vector<int> curr, next; // (energy, visited mask, current position)
        curr.push_back((start << 16) | energy);
        best[start][0] = energy;

        for (int moves = 0; !curr.empty(); moves++) {
            for (auto val : curr) {
                auto u = val >> 16;
                auto mask = (val >> 6) & 1023;
                auto e = val & 63;
                if (mask == target)
                    return moves;
                if (e == 0)
                    continue;

                uint16_t size = (grid[u] >> 1) & 7;
                for (uint16_t i = 0; i < size; ++i) {
                    auto v = adj[u][i];
                    auto nmask = mask | (grid[v] >> 4);
                    auto ne = (grid[v] & 1) ? energy : e - 1;
                    if (ne > best[v][nmask]) {
                        best[v][nmask] = ne;
                        next.push_back((v << 16) | (nmask << 6) | ne);
                    }
                }
            }
            curr.swap(next);
            next.clear();
        }

        return -1;
    }
};